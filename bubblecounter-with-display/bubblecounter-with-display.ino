#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // OLEDs without Reset of the Display

unsigned long currentMillis;
long previousMillis = 0; 

long bubble = 0;
// Overall total bubble counter
long totalbubble = 0;

//Max counter bubble
long maxBubbleInAHour = 0;
//Interval Time for collect the bubbels in a array 
long interval = 60000; //10 secs

//Array for the bubbles
const int bubblearraySize = 60;
int bubbleArray[bubblearraySize]; 
int counter = 0;

bool rizing = false;

int sensorState = 0, lastState=0;
#define SENSORPIN 16


void setup() {
  Serial.begin(9600);
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  
  u8x8.begin();
  u8x8.clear();
}

void loop() {
  pre();
  SetBubbleInArray();
  GetSumBubbleInHour();
  readBubble();
  writeStatusDisplay();
}

void SetBubbleInArray(){
  currentMillis = millis();  
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    bubbleArray[counter] = bubble;
    if(counter == 10){
      counter = 0;
      
    }
    else{
      counter++;
      }  
      bubble = 0; 
      u8x8.setCursor(0,3);
     u8x8.clear();
  }
}

void GetSumBubbleInHour()
{
  int total = 0;
  for ( int i = 0; i < bubblearraySize; ++i )
      total += bubbleArray[ i ];
  Serial.println(total);
  Serial.println(maxBubbleInAHour);
  if(maxBubbleInAHour < total){
    maxBubbleInAHour = total;
    rizing = true;
  }
  else{
    rizing = false;
  }
}

void readBubble(){
  //Read the pullup sensor
  sensorState = digitalRead(SENSORPIN);

  if (!sensorState && lastState) {
    Serial.println("Broken");
    bubble++;
    totalbubble++;
  }
  lastState = sensorState;
}

void writeStatusDisplay(){
  u8x8.setCursor(0,1);
  u8x8.print("Total: ");
  
  u8x8.print(totalbubble);
  u8x8.setCursor(0,2);
  u8x8.print("Max  : ");
  u8x8.print(maxBubbleInAHour);
  if(rizing){
    u8x8.print(" U");
  }
  else{
    u8x8.print(" D");
  }

  u8x8.setCursor(0,3);
  u8x8.setFont(u8x8_font_inb33_3x6_n);
  u8x8.print(bubble);
}

void pre(void)
{
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  u8x8.setCursor(0,0); 
  u8x8.print("-=[ BUBBLES ]=-");
  u8x8.setFont(u8x8_font_chroma48medium8_r);  
  u8x8.setCursor(0,2);
}