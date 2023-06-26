/*
 * desklab.h
 * =========
 *
 * Bibliothek zur Nutzung mit dem Experimentier-Set von desklab
 * (www.desk-lab.de).
 *
 * Zur Verfügung gestellt durch die desklab gUG (haftungsbeschränkt)
 *
 * Copyright 2018-2019 desklab gUG <orga@desk-lab.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE
*/

#ifndef desklab
#define desklab

#include <Adafruit_SSD1306.h>

#define OLED_RESET 4

static Adafruit_SSD1306 oleddisplay(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO_WIDTH 128
#define LOGO_HEIGHT 32

const unsigned char dl_Logo [] PROGMEM= {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0C, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x18, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x33, 0x8E, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x30, 0x06, 0x00, 0x00, 0x60, 0x00, 0x00,
0x00, 0x66, 0xC3, 0x80, 0x00, 0x01, 0x80, 0x00, 0x00, 0x30, 0x06, 0x00, 0x00, 0x60, 0x00, 0x00,
0x00, 0xCC, 0x70, 0xC0, 0x00, 0x01, 0x80, 0x00, 0x00, 0x30, 0x06, 0x00, 0x00, 0x60, 0x00, 0x00,
0x01, 0x98, 0x1C, 0x40, 0x00, 0x01, 0x80, 0x00, 0x00, 0x30, 0x06, 0x00, 0x00, 0x60, 0x00, 0x00,
0x03, 0x30, 0x06, 0x40, 0x00, 0x01, 0x80, 0x00, 0x00, 0x30, 0x06, 0x00, 0x00, 0x60, 0x00, 0x00,
0x06, 0x60, 0x00, 0x00, 0x00, 0xF9, 0x83, 0xE0, 0x7C, 0x30, 0x66, 0x03, 0xE0, 0x67, 0xC0, 0x00,
0x04, 0xC0, 0x02, 0x40, 0x01, 0xDD, 0x87, 0x70, 0xEE, 0x30, 0xC6, 0x07, 0x78, 0x6E, 0xE0, 0x00,
0x04, 0x80, 0x02, 0x40, 0x03, 0x07, 0x8C, 0x19, 0xC3, 0x31, 0x86, 0x0C, 0x1C, 0x78, 0x30, 0x00,
0x04, 0x80, 0x02, 0x40, 0x03, 0x03, 0x9C, 0x09, 0x80, 0x33, 0x06, 0x18, 0x0E, 0x70, 0x18, 0x00,
0x04, 0x80, 0x1E, 0x40, 0x06, 0x01, 0x98, 0x38, 0xF0, 0x36, 0x06, 0x18, 0x06, 0x60, 0x18, 0x00,
0x04, 0x80, 0x12, 0x40, 0x06, 0x01, 0x9F, 0xF0, 0x7C, 0x3C, 0x06, 0x18, 0x06, 0x60, 0x18, 0x00,
0x04, 0x80, 0x12, 0x48, 0x06, 0x01, 0x98, 0x00, 0x0F, 0x3F, 0x06, 0x18, 0x06, 0x60, 0x18, 0x00,
0x04, 0xC0, 0x1E, 0x78, 0x03, 0x03, 0x98, 0x00, 0x03, 0x33, 0x86, 0x18, 0x0E, 0x70, 0x18, 0x00,
0x06, 0x60, 0x00, 0x00, 0x03, 0x07, 0x0C, 0x19, 0x83, 0x30, 0xC6, 0x0C, 0x1E, 0x38, 0x30, 0x00,
0x03, 0x30, 0x06, 0x40, 0x01, 0xDE, 0x07, 0x79, 0xEE, 0x30, 0x67, 0x67, 0x36, 0x1E, 0xE0, 0x00,
0x01, 0x98, 0x1C, 0x40, 0x00, 0xF8, 0x03, 0xE0, 0x7C, 0x30, 0x63, 0xE3, 0xE6, 0x07, 0xC0, 0x00,
0x00, 0xCC, 0x70, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x66, 0xC3, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x33, 0x8E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x18, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0C, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

double PhotometerSensorAuslesen(int sensorPin);
double PhotometerBerechnung(double sensorValue);
double PhotometerMessung(int sensorPin);
void StarteDisplay();
void PhotometerAusgabe(double opticalDensity);
void TextAusgabe(String printMessage, int printSize);
void Drehen(int drehen);
Adafruit_SSD1306 Display();

#endif