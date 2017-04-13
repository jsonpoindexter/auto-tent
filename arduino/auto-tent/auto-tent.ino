// auto-tent

// HC-SR501 Motion Detector setup
int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 8; // Input for HC-S501
int motionDetected; // Place to store read PIR Valu
int detectionBlock = 3000; // motion sensor is not able to detect for 3 seconds
int noMotionPeriod = 5000 + detectionBlock; // how many second to wait while no motion is detected befor fading out lights
long previousMillis = 0;        // will store last time LED was updated
bool timeOutReached = true;

bool currentMotionState = LOW;
bool previousMotionState = LOW;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
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
      turnOnLeds();
    }
    else{
      Serial.println(currentMillis - previousMillis);
      if(currentMotionState != previousMotionState){
        //Serial.println("Hit motion detection switch");
        previousMillis = currentMillis;
        timeOutReached = false;
        previousMotionState = currentMotionState;
        
      }
      if( currentMillis - previousMillis > noMotionPeriod ){
        timeOutReached = true;
        //Serial.println("Motion is NOT detected");
        previousMillis = currentMillis;
        turnOffLeds();
      }
    }
  }
}

void turnOnLeds(){
  Serial.println("Turn LEDs ON");
}

void turnOffLeds(){
  Serial.println("Turn LEDs OFF");
}


