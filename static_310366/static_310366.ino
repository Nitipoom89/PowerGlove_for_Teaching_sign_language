/* Edge Impulse ingestion SDK
 * Copyright (c) 2022 EdgeImpulse Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
//***************************************************************************************//interruot
#if !( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD51__) || defined(__SAMD51J20A__) \
      || defined(__SAMD51J19A__) || defined(__SAMD51G19A__) || defined(__SAMD51P19A__)  \
      || defined(__SAMD21E15A__) || defined(__SAMD21E16A__) || defined(__SAMD21E17A__) || defined(__SAMD21E18A__) \
      || defined(__SAMD21G15A__) || defined(__SAMD21G16A__) || defined(__SAMD21G17A__) || defined(__SAMD21G18A__) \
      || defined(__SAMD21J15A__) || defined(__SAMD21J16A__) || defined(__SAMD21J17A__) || defined(__SAMD21J18A__) )
  #error This code is designed to run on SAMD21/SAMD51 platform! Please check your Tools->Board setting.
#endif

#define TIMER_INTERRUPT_DEBUG         0
#define _TIMERINTERRUPT_LOGLEVEL_     0
#define USING_TIMER_TC3         true      // Only TC3 can be used for SAMD51
#define USING_TIMER_TC4         false     // Not to use with Servo library
#define USING_TIMER_TC5         false
#define USING_TIMER_TCC         false
#define USING_TIMER_TCC1        false
#define USING_TIMER_TCC2        false     // Don't use this, can crash on some boards 
#include "SAMDTimerInterrupt.h"
#include "SAMD_ISR_Timer.h"

#define HW_TIMER_INTERVAL_MS      10

///////////////////////////////////////////////

#if (TIMER_INTERRUPT_USING_SAMD21)
  #if USING_TIMER_TC3
    #define SELECTED_TIMER      TIMER_TC3
  #elif USING_TIMER_TC4
    #define SELECTED_TIMER      TIMER_TC4
  #elif USING_TIMER_TC5
    #define SELECTED_TIMER      TIMER_TC5
  #elif USING_TIMER_TCC
    #define SELECTED_TIMER      TIMER_TCC
  #elif USING_TIMER_TCC1
    #define SELECTED_TIMER      TIMER_TCC1
  #elif USING_TIMER_TCC2
    #define SELECTED_TIMER      TIMER_TCC
  #else
    #error You have to select 1 Timer  
  #endif
#else
  #if !(USING_TIMER_TC3)
    #error You must select TC3 for SAMD51
  #endif
  
  #define SELECTED_TIMER      TIMER_TC3
#endif  
SAMDTimer ITimer(SELECTED_TIMER);

////////////////////////////////////////////////

SAMD_ISR_Timer ISR_Timer;
#define TIMER_INTERVAL_1S             15L

//*********************************************************************************************

#include <cstdarg>

#define EIDSP_USE_CMSIS_DSP             1
#define EIDSP_LOAD_CMSIS_DSP_SOURCES    1

#define __STATIC_FORCEINLINE                   __attribute__((always_inline)) static inline
#define __SSAT(ARG1, ARG2) \
__extension__ \
({                          \
  int32_t __RES, __ARG1 = (ARG1); \
  __ASM volatile ("ssat %0, %1, %2" : "=r" (__RES) :  "I" (ARG2), "r" (__ARG1) : "cc" ); \
  __RES; \
 })

/* Includes -------------------------------------------------------------------------------------------------------- */
#include <powerGlove_all_inferencing.h>

#include "FastIMU.h"
#define IMU_ADDRESS 0x6A
LSM6DS3 IMU;                  // Currently supported IMUS: MPU9255 MPU9250 MPU6500 MPU6050 ICM20689 ICM20690 BMI055 BMX055 BMI160 LSM6DS3 LSM6DSL 

#include "Madgwick.h"
#include <Wire.h>
#include "SparkFun_Displacement_Sensor_Arduino_Library.h" 
ADS myFlexSensor1; //Create instance of the Angular Displacement Sensor (ADS) class for sensor 1
ADS myFlexSensor2; //Create instance of the Angular Displacement Sensor (ADS) class for sensor 2
ADS myFlexSensor3; //Create instance of the Angular Displacement Sensor (ADS) class for sensor 3
ADS myFlexSensor4; //Create instance of the Angular Displacement Sensor (ADS) class for sensor 4
ADS myFlexSensor5; //Create instance of the Angular Displacement Sensor (ADS) class for sensor 5

#define PERFORM_CALIBRATION //Comment to disable startup calibration
float qw,qx,qy,qz,ax,ay,az,ggw=0.0f,ggx=0.0f,ggy=0.0f,ggz=0.0f;
float roll,pitch,yaw;
float Thumb,Index,Middle,Ring,Pinky;

calData calib = { 0 };  //Calibration data
AccelData IMUAccel;    //Sensor data
GyroData IMUGyro;
MagData IMUMag;
Madgwick filter;
AccelData accelData;    //Sensor data

float Thumb_map = 0;
float Index_map = 0;            
float Middle_map= 0;
float Ring_map  = 0;
float Pinky_map = 0;
int case_value = 0;
int send_result = 99;  //99 คือไม่มีท่าทางที่ทำ
unsigned long period = 2000; //ระยะเวลาที่ต้องการรอ    ในการ sampling ค่า ท่า static
unsigned long last_time = 0; //ประกาศตัวแปรเป็น global เพื่อเก็บค่าไว้ไม่ให้ reset จากการวนloop
const float accelerationThreshold = 80;  //movement แยก case
int threshold = 0;   // check movement
int confidence = 90;
String Label;
int check_move = 0;

//********************************************************************************//get value from Unity
int receiver_UI; 

void TimerHandler(void)
{
  ISR_Timer.run();
}
void doingSomething1()
{
                IMU.update();
                IMU.getGyro(&IMUGyro);
                IMU.getAccel(&IMUAccel);
                filter.updateIMU(IMUGyro.gyroX, IMUGyro.gyroY, IMUGyro.gyroZ, IMUAccel.accelX, IMUAccel.accelY, IMUAccel.accelZ);                
                qw=filter.getQuatW();
                qx=filter.getQuatX();
                qy=filter.getQuatY();
                qz=filter.getQuatZ();
                
                ax=IMUAccel.accelX*100;
                ay=IMUAccel.accelY*100;
                az=IMUAccel.accelZ*100;

                if (myFlexSensor1.available() == true && myFlexSensor2.available()== true && myFlexSensor3.available() == true 
                 && myFlexSensor4.available() == true && myFlexSensor5.available() == true)
                {        
                    Thumb=myFlexSensor4.getX();
                    Index=myFlexSensor3.getX();
                    Middle=myFlexSensor5.getX();
                    Ring=myFlexSensor2.getX();
                    Pinky=myFlexSensor1.getX();              
      
                    Thumb_map =map(Thumb,-260.0f,-80.0f,0,100);
                    Index_map =map(Index,-300.0f,-40.0f,0,100);            
                    Middle_map=map(Middle,-350.0f,-20.0f,0,100);
                    Ring_map  =map(Ring,-240.0f,-10.0f,0,100);
                    Pinky_map =map(Pinky,-240.0f,-20.0f,0,100);
                    
                    //This code ensures that the variables Thumb_map, Index_map, Middle_map, Ring_map, and Pinky_map are within the range of 0 to 100.
                    if(Thumb_map >=100) { Thumb_map=100;}   else if(Thumb_map <=1) { Thumb_map=0;}
                    if(Index_map >=100) { Index_map=100;}   else if(Index_map <=1) { Index_map=0;}
                    if(Middle_map >=100) { Middle_map=100;} else if(Middle_map <=1) { Middle_map=0;}
                    if(Ring_map >=100) { Ring_map=100;}     else if(Ring_map <=1) { Ring_map=0;}
                    if(Pinky_map >=100) { Pinky_map=100;}   else if(Pinky_map <=1) { Pinky_map=0;}

                }

                Serial.print(qw);
                Serial.print(",");
                Serial.print(qx);
                Serial.print(",");
                Serial.print(qy);
                Serial.print(",");
                Serial.print(qz);
                Serial.print(",");
                Serial.print(Thumb);
                Serial.print(",");
                Serial.print(Index);
                Serial.print(",");
                Serial.print(Middle);
                Serial.print(",");
                Serial.print(Ring);
                Serial.print(",");
                Serial.print(Pinky);
                Serial.print(",");
                Serial.println(send_result);
}

//***********************************************************************************************************//
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  Wire.begin();
  while (!Serial) {
    ;
  }

  if (myFlexSensor1.begin(0xA) == false || myFlexSensor2.begin(0xB) == false 
   || myFlexSensor3.begin(0xC) == false || myFlexSensor4.begin(0xD) == false 
   || myFlexSensor5.begin(0xE) == false) 
  {
    Serial.println(F("One or more sensors not detected. Check wiring. Freezing..."));
    while (1)
      ;
  }
  myFlexSensor1.enableStretching(true);  // Enable receiving stretching data for sensor 1
  myFlexSensor2.enableStretching(true);  // Enable receiving stretching data for sensor 2
  myFlexSensor3.enableStretching(true);  // Enable receiving stretching data for sensor 3
  myFlexSensor4.enableStretching(true);  // Enable receiving stretching data for sensor 4
  myFlexSensor5.enableStretching(true);  // Enable receiving stretching data for sensor 5
  int err = IMU.init(calib, IMU_ADDRESS);
  if (err != 0) {
    Serial.print("Error initializing IMU: ");
    Serial.println(err);
    while (true) {
      ;
    }
  }

  if (err != 0) {
    Serial.print("Error Setting range: ");
    Serial.println(err);
    while (true) {
      ;
    }
  }

  #ifdef PERFORM_CALIBRATION
  IMU.calibrateAccelGyro(&calib);
  IMU.init(calib, IMU_ADDRESS);
  filter.begin(0.6f);
  #endif

  //********************************************************************************************///interrupt
  while (!Serial && millis() < 5000);
  if (ITimer.attachInterruptInterval_MS(HW_TIMER_INTERVAL_MS, TimerHandler))
  {
    Serial.print(F("Starting ITimer OK, millis() = ")); Serial.println(millis());
  }
  else
  Serial.println(F("Can't set ITimer. Select another freq. or timer"));
  ISR_Timer.setInterval(TIMER_INTERVAL_1S,  doingSomething1);
  //*************************************************************************************************////
}

void loop() {
  if(Serial.available()){
    receiver_UI = Serial.read();
    if(receiver_UI == 'S'){
       case_value = 1;
       digitalWrite(LED_BUILTIN, HIGH);
    } else if (receiver_UI == 'M'){
       case_value = 2;
       digitalWrite(LED_BUILTIN, LOW);
      }
      else if (receiver_UI == 'A'){
       send_result = 99;
      }
  }
    switch (case_value) {
    case 1: {
            if( millis() - last_time > period) {
                last_time = millis(); 
                float Raw_Data[7] = {((ax*-1)-30), (Thumb_map-10), Index_map, (Middle_map-10), (Ring_map-20), (Pinky_map-10)};
                char result[7] = {};
                int pose_key[11] = {100000,101000,101100,111100,101111,111111,101110,101101,101011,100111};
                int pose_result[11] = { 0,1,2,3,4,5,6,7,8,9 };
                for(int j = 0; j < 6; j++) {
                  if(Raw_Data[j] > 50) {
                        result[j] = {'1'};             
                  } else {
                        result[j] = {'0'};
                  }
                }
                for(int j = 0; j < 10; j++){
                  if(String(result) == String(pose_key[j])) {
                        send_result = pose_result[j];
                        break;              
                  } else {
                        send_result = 99; 
                  }
                }    
              }
    }break;
    case 2: {
        float buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE] = { 0 };
        for (size_t ix = 0; ix < EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE; ix += 8) {
            uint64_t next_tick = micros() + (EI_CLASSIFIER_INTERVAL_MS * 1000);
                buffer[ix] = ax;
                buffer[ix+1] = ay;
                buffer[ix+2] = az;        
                buffer[ix+3] = Thumb_map;
                buffer[ix+4] = Index_map;  
                buffer[ix+5] = Middle_map;
                buffer[ix+6] = Ring_map;
                buffer[ix+7] = Pinky_map;
                delayMicroseconds(next_tick - micros());
        }   
                            ei_impulse_result_t result;
                            signal_t signal;
                            numpy::signal_from_buffer(buffer, EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, &signal);

                            // run classifier
                            EI_IMPULSE_ERROR res = run_classifier(&signal, &result, false);
              if (res != 0) return;
                #if EI_CLASSIFIER_HAS_ANOMALY == 1
                    if(result.anomaly < threshold) {
                        for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
                            if(((result.classification[ix].value)*100) > confidence )
                            {
                                Label = String(result.classification[ix].label);
                                //Serial.println("********************");
                                if (Label == "ten" && (ax*-1) > 60 && Thumb_map < 40 && Index_map < 10)
                                {
                                  send_result = 10;
                                }
                                else if (Label == "pink")
                                {
                                  send_result = 11;
                                }
                                else if (Label == "blue" && (ax*-1) > 50 && Middle_map > 50 && Pinky_map > 50 )
                                {
                                  send_result = 12;
                                }
                                else if (Label == "yellow" && (ax*-1) > 50 && Thumb_map > 50 && Index_map > 50)
                                {
                                  send_result = 13;
                                }
                                else { send_result = 99; }
                              }
                        }
                    } 
                    else { send_result = 99; }
                  #endif 
      }break;
    }
  }






