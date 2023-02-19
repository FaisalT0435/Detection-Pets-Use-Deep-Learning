




// change setup.h to switch between buffered and pixel-by-pixel processing
#include "setup.h"
const int MOTION_SENSOR_PIN = 10;   // Arduino pin connected to the OUTPUT pin of motion sensor
const int buzzer        = 8;   // Arduino pin connected to Buzzer's pin
int motionStateCurrent      = LOW; // current  state of motion sensor's pin
int motionStatePrevious     = LOW; 
int i ;
int x;

void setup() {
  // This is not necessary and has no effect for ATMEGA based Arduinos.
  // WAVGAT Nano has slower clock rate by default. We want to reset it to maximum speed
  Serial.begin(9600);  
  pinMode(buzzer,OUTPUT);              
  pinMode(MOTION_SENSOR_PIN, INPUT); // set arduino pin to input mode
//  pinMode(BUZZER_PIN, OUTPUT);  
  CLKPR = 0x80; // enter clock rate change mode
  CLKPR = 0; // set prescaler to 0. WAVGAT MCU has it 3 by default.

  initializeScreenAndCamera();
}


void loop() {
//  String teststr = Serial.readString();
//  Serial.println(teststr);
//  
//  if (teststr == 1){
//      digitalWrite(BUZZER_PIN, HIGH); 
////      Serial.println("Suara Bunyi");
//  }
      digitalWrite(buzzer, HIGH);

      if (Serial.available() > 0){
      x = Serial.read();
      Serial.println(x);
          if ( x == 1){
            digitalWrite(buzzer, LOW);
            tone(buzzer,261);    
            // Waits some time to turn off
            delay(200);
            //Turns the buzzer off
            noTone(buzzer); 
            // Sounds the buzzer at the frequency relative to the note D in Hz   
            tone(buzzer,293);             
            delay(200);    
            noTone(buzzer); 
            // Sounds the buzzer at the frequency relative to the note E in Hz
            tone(buzzer,329);      
            delay(200);
            noTone(buzzer);     
            // Sounds the buzzer at the frequency relative to the note F in Hz
            tone(buzzer,349);    
            delay(200);    
            noTone(buzzer); 
            // Sounds the buzzer at the frequency relative to the note G in Hz
            tone(buzzer,392);            
            delay(200);
            noTone(buzzer);  
           }
       else{ 
            digitalWrite(buzzer, HIGH);
            delay(700);
            
        }
    }

  motionStatePrevious = motionStateCurrent;            // store old state
  motionStateCurrent  = digitalRead(MOTION_SENSOR_PIN); // read new state

  if (motionStatePrevious == LOW && motionStateCurrent == HIGH) { // pin state change: LOW -> HIGH
    Serial.println("Motion detected!");
    for (i=0; i<40; i++){
      processFrame();  
    }
    
//    initializeScreenAndCamera();
//    digitalWrite(BUZZER_PIN, HIGH); // turn on
  }
  else if (motionStatePrevious == HIGH && motionStateCurrent == LOW) { // pin state change: HIGH -> LOW
    Serial.println("Motion stopped!");
//    digitalWrite(BUZZER_PIN, LOW);  // turn off
  }
 

 
//  processFrame();
}
