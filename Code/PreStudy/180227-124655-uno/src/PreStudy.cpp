#include <Arduino.h>
/* TODO
  - user study protocol
  - order of testcases
  - time to perception calculation via interrupt button
  - where to start the time measurement before or after the start of stimulus
  - how to handle the time measurement of sound played by processing (delays?)
  - how to handle the LED after button press
*/
const int led = 12;
const int red = 11;
const int blue = 10;
const int motor = 9;
const int cooling = 13;
const int interuptButton = 7;
int wait = 50;
int intensity = 0;
int motorIntensity = 0;
bool ledUp = true; // used in ledPulse
char serial;
String condition = "water";
bool wasInterrupted = false;
bool stimulusActive = false;
unsigned long ttp = 0; // time to perception.
unsigned long startTime = 0;
int stimuliArray[] = {0,1,2,3,4,0,2,1,0,4,9};
int randomNumber;
//int stimuliArray[] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4};
int inByte = 0;
int caseCounter = 0;
const int maxCases = 25;


void ledPulse(String color);
void motorAction(int intensity);
void peltierAction();
void buttonPressed();
void resetAll();
void playSound();
void studyFinished();
void establishConnection();
void ledAction();
void slowMotorAction();

void setup() {
  // put your setup code here, to run once:
  pinMode(cooling, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(motor, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  pinMode(interuptButton, INPUT_PULLUP);
  //wait for the button to be pressed before start
  while (digitalRead(interuptButton) == 1) {
    ;
  }
  delay(2000);
}

void loop() {
  
  if((Serial.available() >= 0) || stimulusActive){ //only proceed if processing is done with its part and ready to receive

    if (!stimulusActive) { //choose new stimulus after last one was handled
      wasInterrupted = false;

      if (condition == "water") { // random number without sound for water
        randomNumber = random(0,4);
      } else if (condition == "land"){
        randomNumber = random(0,5);
      } else if (condition == "finished"){
        randomNumber = 9;
      }

      if (caseCounter < maxCases) {
        caseCounter++;
      } else {
        condition = "finished";
      }

      switch (randomNumber) {
        case 0:
          stimulusActive = true;
          ledPulse("red");
          break;
        case 1:
          stimulusActive = true;
          motorAction(168);
          break;
        case 2:
          stimulusActive = true;
          peltierAction();
          break;
        case 3:
          stimulusActive = true;
          ledAction();
          break;
        case 4:
          stimulusActive = true;
          slowMotorAction();
          break;
        case 5:
          stimulusActive = true;
          playSound();
          break;
        case 9: studyFinished();
          break;
        default: break;
      }
      //stimIterator++;
    }

    if (wasInterrupted){ //reset for next stimulus after button was pressed
      ttp = millis() - startTime;
      resetAll();
      wasInterrupted = false;
      digitalWrite(red, HIGH);
      delay(500);
      digitalWrite(red, LOW);
      Serial.print("D");
      Serial.print(randomNumber);
      Serial.print("t");
      Serial.print(ttp);
      Serial.println("x");
      delay(2000);
      delay(random(0,5)*1000);
      stimulusActive = false;
    }
  }
}

// callback for interrupt by button press
void buttonPressed(){
  wasInterrupted = true;
  Serial.println("buttonPressed");
}

//turn on motor with corresponding intensity
void motorAction(int motorIntensity){
  detachInterrupt(2);
  analogWrite(motor, motorIntensity);
  startTime = millis();
  while (digitalRead(interuptButton) == 1) {
    ;
  }
  wasInterrupted = true;
}

//send signal to processing to play the playSound
void playSound(){
  Serial.print("S");
  Serial.print(randomNumber);
  Serial.println("x");
  while (digitalRead(interuptButton) == 1) {
    digitalWrite(blue, 255);
  }
  digitalWrite(blue, 0);
  Serial.print('I');
  Serial.print(randomNumber);
  Serial.println("x");
  wasInterrupted = false;
  stimulusActive = false;
  delay(2000);
  delay(random(0,5) * 1000);
}

//turn on peltier
void peltierAction(){
  digitalWrite(cooling, HIGH);
  startTime = millis();
  while (digitalRead(interuptButton) == 1) {
    ;
  }
  wasInterrupted = true;
}

void resetAll(){
  analogWrite(led, 0);
  analogWrite(red, 0);
  analogWrite(blue, 0);
  analogWrite(motor, 0);
  digitalWrite(cooling, LOW);
  intensity = -15;
}

// let LED pulse one time
void ledPulse(String color){
  stimulusActive = true;
  intensity = 1;
  ledUp = true;
  startTime = millis();
  while(intensity >= 0 && digitalRead(interuptButton) == 1){
    analogWrite(red, intensity);
    delay(wait);
    if (ledUp){
      intensity = min(255, intensity + 5);
    }
    if (!ledUp) {
      intensity -= 5;
    }

    if (intensity >= 255){
      ledUp = false;
    }
  }
  while (digitalRead(interuptButton) == 1) {
    ;
  }
  wasInterrupted = true;
}

void ledAction(){
  stimulusActive = true;
  analogWrite(red, 255);
  while (digitalRead(interuptButton) == 1) {
    ;
  }
  wasInterrupted = true;
}

void slowMotorAction(){
  stimulusActive = true;
  intensity = 1;
  startTime = millis();
  while(intensity >= 0 && digitalRead(interuptButton) == 1){
    analogWrite(motor, intensity);
    delay(wait);
      intensity = min(168, intensity + 5);
  }
  while (digitalRead(interuptButton) == 1) {
    ;
  }
  wasInterrupted = true;
}

void studyFinished(){
  detachInterrupt(2);
  Serial.println("Fx");
  while(1){
    ;
  }
}
