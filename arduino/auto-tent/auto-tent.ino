// auto-tent

//FastLED Setup
#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define MAX_BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

int color = CRGB::White;
int fadeSpeed = 1; //how fast to fade from Black to MAX_BRIGHTNESS

// HC-SR501 Motion Detector setup
int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 8; // Input for HC-S501
int motionDetected; // Place to store read PIR Valu
int detectionBlock = 3000; // motion sensor is not able to detect for 3 seconds
int noMotionPeriod = 10000 + detectionBlock; // how many second to wait while no motion is detected before fading out lights
long previousMillis = 0;        // will store last time LED was updated
bool timeOutReached = true;

bool currentMotionState = LOW;
bool previousMotionState = LOW;

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  MAX_BRIGHTNESS );
  FastLED.show();
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Starting sketch...");
  //initialize motion sensor
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}


void loop() {
  
  unsigned long currentMillis = millis();
  
  currentMotionState = digitalRead(pirPin);
  
  digitalWrite(ledPin, currentMotionState);
  
  if( ( currentMotionState != previousMotionState )  || ( (currentMotionState == LOW) && (!timeOutReached) ) ){
    if(currentMotionState == true){
      previousMotionState = currentMotionState;
      Serial.println("Motion is detected");
      if(timeOutReached){
        turnOnLeds();
      }
    }
    else{
      //Serial.println(currentMillis - previousMillis);
      if(currentMotionState != previousMotionState){
        //Serial.println("Hit motion detection switch");
        previousMillis = currentMillis;
        timeOutReached = false;
        previousMotionState = currentMotionState;
        
      }
      if( currentMillis - previousMillis > noMotionPeriod ){
        timeOutReached = true;
        Serial.println("Motion is NOT detected");
        previousMillis = currentMillis;
        turnOffLeds();
      }
    }
  }
}


void turnOnLeds(){
  Serial.println("Turn LEDs ON");
  for(int brightness = 1; brightness <= MAX_BRIGHTNESS; brightness++){
    for( int i = 0; i < NUM_LEDS; i++) {
      leds[i] = color; 
    }
    FastLED.setBrightness( brightness );
    Serial.println(brightness);
    FastLED.show();
    delay( (fadeSpeed * 1000) / MAX_BRIGHTNESS );
  }
}

void turnOffLeds(){
  Serial.println("Turn LEDs OFF");
  for(int brightness = MAX_BRIGHTNESS; brightness >= 0; brightness--){
    FastLED.setBrightness( brightness );
    Serial.println(brightness);
    FastLED.show();
    delay( (fadeSpeed * 1000) / MAX_BRIGHTNESS );
  }
}
