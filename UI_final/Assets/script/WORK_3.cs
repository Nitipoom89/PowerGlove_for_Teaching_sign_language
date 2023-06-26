using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
public class WORK_3: MonoBehaviour
{

    public SerialPort stream = new System.IO.Ports.SerialPort("COM12",115200, System.IO.Ports.Parity.None, 8, System.IO.Ports.StopBits.One);
    public string receivedstring;
    public float sensitivity = 0.1f;
    public Transform b_r_index3, b_r_index2, b_r_index1,b_r_middle3, b_r_middle2, b_r_middle1 ,RightHand ,b_r_Ring3,b_r_Ring2,b_r_Ring1,b_r_Pinky3,b_r_Pinky2,b_r_Pinky1,b_r_Thumb1,b_r_Thumb2,b_r_Thumb3;
    public float qw, qx, qy, qz,speedFactor = 25.0f,Thumb,Index,Middle,Ring,Pinky,result;
    bool Offset;
    float Thumb_map,Index_map,Middle_map,Ring_map,Pinky_map,Thumb_RAWFILLTER,Index_RAWFILLTER,Middle_RAWFILLTER,Ring_RAWFILLTER,Pinky_RAWFILLTER;
    float offsetValue;
    int Thumb_EMA,Index_EMA,Middle_EMA,Ring_EMA,Pinky_EMA,Choose;
    int startfrist = 0;

    public GameObject correct;
    public GameObject loading;
    public GameObject lesson;

    void Start()
    {   
        loading.SetActive(true);
        startfrist = 1;
        stream.Open();
        Offset=true;
    }

    double UpdateY(double y, double x)                  // ฟังก์ชันสำหรับทำ Moving average
    {
        return 0.92f * y + 0.08f * x;
    }

    float map(float x, float in_min, float in_max, float out_min, float out_max) {
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
    }
        
     IEnumerator DelayCoroutine()
    {
        yield return new WaitForSeconds(5f);
        // Code to execute after 8 seconds delay
    }
    void Update()
    {
        receivedstring = stream.ReadLine();  
        string[] data_Finger=receivedstring.Split(",");               // qw,qx,qy,qz,t,i,m,r,p
    
        string[] data_Raw_thumb = (data_Finger[4]).Split(",");
        string[] data_Raw_index = (data_Finger[5]).Split(",");
        string[] data_Raw_middle= (data_Finger[6]).Split(",");
        string[] data_Raw_ring  = (data_Finger[7]).Split(",");
        string[] data_Raw_pinky = (data_Finger[8]).Split(",");
        string[] data_result = (data_Finger[9]).Split(",");
        // string[] data_Finger_thumb = (data_Raw_thumb[0]).Split(":");
        // string[] data_Finger_index = (data_Raw_index[0]).Split(":");
        // string[] data_Finger_middle= (data_Raw_middle[0]).Split(":");
        // string[] data_Finger_ring  = (data_Raw_ring[0]).Split(":");
        // string[] data_Finger_pinky = (data_Raw_pinky[0]).Split(":");

    
      
        qw = float.Parse(data_Finger[0]);
        qx = float.Parse(data_Finger[1]);
        qy = float.Parse(data_Finger[2]);
        qz = float.Parse(data_Finger[3]);

        Thumb  = float.Parse(data_Raw_thumb[0]);
        Index  = float.Parse(data_Raw_index[0]);
        Middle = float.Parse(data_Raw_middle[0]);
        Ring   = float.Parse(data_Raw_ring[0]);
        Pinky  = float.Parse(data_Raw_pinky[0]);
        result = int.Parse(data_result[0]);
        
        int numReads2 = 30; // number of samples
        int senseSum2 = 0;
        int senseSum3 = 0;
        int senseSum4 = 0;
        int senseSum5 = 0;
        int senseSum6 = 0;
        for(int i = 0; i < numReads2; i++) {
        senseSum2 +=(int)Thumb;
        senseSum3 +=(int)Index;
        senseSum4 +=(int)Middle;
        senseSum5 +=(int)Ring;
        senseSum6 +=(int)Pinky;
        
        }
        int senseAve2 = senseSum2 /numReads2 ; // average sensor readings
        int senseAve3 = senseSum3 /numReads2 ; // average sensor readings
        int senseAve4 = senseSum4 /numReads2 ; // average sensor readings
        int senseAve5 = senseSum5 /numReads2 ; // average sensor readings
        int senseAve6 = senseSum6 /numReads2 ; // average sensor readings 

        Thumb_RAWFILLTER =(int)UpdateY(Thumb_RAWFILLTER,senseAve2);
        Index_RAWFILLTER =(int)UpdateY(Index_RAWFILLTER,senseAve3);
        Middle_RAWFILLTER=(int)UpdateY(Middle_RAWFILLTER,senseAve4);
        Ring_RAWFILLTER  =(int)UpdateY(Ring_RAWFILLTER,senseAve5);
        Pinky_RAWFILLTER =(int)UpdateY(Pinky_RAWFILLTER,senseAve6);

        Thumb_map =map(Thumb_RAWFILLTER,-80.0f,-260.0f,0,100);
        Index_map =map(Index_RAWFILLTER,-40.0f,-300.0f,0,100);            
        Middle_map=map(Middle_RAWFILLTER,-20.0f,-350.0f,0,100);
        Ring_map  =map(Ring_RAWFILLTER,-40.0f,-340.0f,0,100);
        Pinky_map =map(Pinky_RAWFILLTER,-20.0f,-240.0f,0,100);

         if(Thumb_map >=100) { Thumb_map=100;}
        else if(Thumb_map <=1) { Thumb_map=0;}
        if(Index_map >=100) { Index_map=100;}
        else if(Index_map <=1) { Index_map=0;}
        if(Middle_map >=100) { Middle_map=100;}
        else if(Middle_map <=1) { Middle_map=0;}
        if(Ring_map >=100) { Ring_map=100;}
        else if(Ring_map <=1) { Ring_map=0;}
        if(Pinky_map >=100) { Pinky_map=100;}
        else if(Pinky_map <=1) { Pinky_map=0;}

        Thumb_EMA =(int)Thumb_map;
        Index_EMA =(int)Index_map;
        Middle_EMA=(int)Middle_map;
        Ring_EMA  =(int)Ring_map;
        Pinky_EMA =(int)Pinky_map;
            
        if (Offset)
        {    StartCoroutine(DelayCoroutine());
             offsetValue = Mathf.Abs(qz - 0f);
             Debug.Log("Offset value: " + offsetValue);
             Offset=false;
        }
        
        if(qw > 0.94 && startfrist == 1 ){
            loading.SetActive(false);
            lesson.SetActive(true);
            startfrist = 0;
        }

        Debug.Log($"qw: {qw} | qx: {qx}| qy: {qy} | qz: {qz} | Index: {Index} | Index_EMA: {Index_EMA} | result: {result}");
                                                                                                       // -qx,-qz,-qy,qw
        //** อันนี้ใช้ได้ MPU6050      RightHand.transform.localRotation = Quaternion.Lerp(transform.localRotation,new Quaternion(qy,-qz,-qx,qw),Time.deltaTime*speedFactor);
        //** อันนี้ใช้ได้ LSM6DS3     
        
        RightHand.transform.localRotation = Quaternion.Lerp(transform.localRotation,new Quaternion(-qy,-qz+offsetValue+0.15f,qx,qw),Time.deltaTime*speedFactor);
        
         // Thumb FINGER
        int received_angle_Thumb1 = (int)Thumb_EMA;
        int received_angle_Thumb2 = (int)Thumb_EMA;
        int received_angle_Thumb3 = (int)Thumb_EMA;
        b_r_Thumb1.transform.localEulerAngles = new Vector3(2.56f,173.43f,((-received_angle_Thumb1*0.75f)*0.5f)+42.76f);
        b_r_Thumb2.transform.localEulerAngles = new Vector3(0,0,((-received_angle_Thumb2*0.80f)*1.5f)+10.0f);
        b_r_Thumb3.transform.localEulerAngles = new Vector3(0,0,(-received_angle_Thumb3*0.15f)*1.5f);
              
        // INDEX FINGER 
        int received_angle_index1 = (int)Index_EMA;
        int received_angle_index2 = (int)Index_EMA;
        int received_angle_index3 = (int)Index_EMA;
        b_r_index1.transform.localEulerAngles = new Vector3(-74.87f,98.22f,((-received_angle_index1*0.75f)*0.75f)+69.24f);
        b_r_index2.transform.localEulerAngles = new Vector3(0,0,(-received_angle_index2*0.80f)*1.5f);
        b_r_index3.transform.localEulerAngles = new Vector3(0,0,(-received_angle_index3*0.80f)*0.0f);
        //****************************************************************

         // Middle FINGER 
        int received_angle_middle1 = (int)Middle_EMA;
        int received_angle_middle2 = (int)Middle_EMA;
        int received_angle_middle3 = (int)Middle_EMA;
        b_r_middle1.transform.localEulerAngles = new Vector3(-80.39f,18.783f,((-received_angle_middle1*0.70f)*0.75f)+151.9f);
        b_r_middle2.transform.localEulerAngles = new Vector3(0,0,(-received_angle_middle2*0.80f)*1.5f);
        b_r_middle3.transform.localEulerAngles = new Vector3(0,0,(-received_angle_middle3*0.80f)*0.50f);
        //****************************************************************

        // Ring FINGER 
        int received_angle_Ring1 = (int)Ring_EMA;
        int received_angle_Ring2 = (int)Ring_EMA;
        int received_angle_Ring3 = (int)Ring_EMA;
        b_r_Ring1.transform.localEulerAngles = new Vector3(-75.48f,-14.72f,((-received_angle_Ring1*1.0f)*0.5f)-179.87f);
        b_r_Ring2.transform.localEulerAngles = new Vector3(0,0,(-received_angle_Ring2*1.0f)*1.5f);
        b_r_Ring3.transform.localEulerAngles = new Vector3(0,0,(-received_angle_Ring3*0.5f)*0.5f);
        //****************************************************************

        // Pinky FINGER
          
         int received_angle_Pinky1 = (int)Pinky_EMA;
         int received_angle_Pinky2 = (int)Pinky_EMA;
         int received_angle_Pinky3 = (int)Pinky_EMA;
         //b_r_Pinky0.transform.localEulerAngles = new Vector3(-53.77f,-27.57f,(-received_angle_Pinky0*0.5f)+37.00f);
         b_r_Pinky1.transform.localEulerAngles = new Vector3(3.38f,11.57f,((-received_angle_Pinky1*1.0f)*0.75f)+175.00f);
         b_r_Pinky2.transform.localEulerAngles = new Vector3(0,0,(-received_angle_Pinky2*0.8f)*1.5f);
         b_r_Pinky3.transform.localEulerAngles = new Vector3(0,0,(-received_angle_Pinky3*0.5f)*0.5f);
        //****************************************************************

        if(Choose == result){
            correct.SetActive(true);
        }
    }

    public void clearChoose()
    {
        Choose = 55;
    }

    public void pose_static()
    {
        if(stream.IsOpen == false){
         stream.Open();
        }
        stream.Write("S");
    }

    public void pose_dynamic()
    {
        if(stream.IsOpen == false){
         stream.Open();
        }
        stream.Write("M");
    }

    public void again_repeat()
    {
        if(stream.IsOpen == false){
         stream.Open();
        }
        stream.Write("A");
    }

    public void num0()
    {
        Choose = 0;
    }
    public void num1()
    {
        Choose = 1;
    }
    public void num2()
    {
        Choose = 2;
    }
    public void num3()
    {
        Choose = 3;
    }
    public void num4()
    {
        Choose = 4;
    }
    public void num5()
    {
        Choose = 5;
    }
    public void num6()
    {
        Choose = 6;
    }
    public void num7()
    {
        Choose = 7;
    }
    public void num8()
    {
        Choose = 8;
    }
    public void num9()
    {
        Choose = 9;
    }
    public void num10()
    {
        Choose = 10;
    }
    public void pinkk()
    {
        Choose = 11;
    }
    public void bluee()
    {
        Choose = 12;
    }
    public void yelloww()
    {
        Choose = 13;
    }
   
}
