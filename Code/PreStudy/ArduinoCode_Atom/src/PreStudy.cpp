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
const int abortButton = 2;
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
int randomNumber;
/* 1 *///int stimuliArray[] = {1,0,1,1,2,3,0,3,4,0,2,1,3,4,4,1,5,4,0,3,2,1,4,0,3,0,3,3,0,2,0,4,5,3,2,5,4,1,2,5,1,4,9};
/* 2 *///int stimuliArray[] = {2,1,5,4,4,5,1,5,4,1,5,3,3,4,1,5,0,1,4,0,5,5,4,2,4,2,0,5,3,1,2,1,2,2,3,2,0,3,4,2,3,1,9};
/* 3 *///int stimuliArray[] = {1,0,1,3,1,4,1,3,0,1,5,1,4,1,1,3,5,3,3,5,2,2,5,0,4,2,5,2,0,5,2,3,0,3,4,2,4,3,5,2,2,5,9};
/* 4 */int stimuliArray[] = {5,4,5,0,0,1,1,3,1,0,4,5,3,1,0,4,3,2,1,2,5,3,5,1,3,5,0,4,5,4,5,2,0,3,0,1,2,4,2,0,3,4,9};
/* 5 *///int stimuliArray[] = {0,5,3,1,3,2,1,2,2,1,0,2,4,5,4,5,4,0,5,5,0,3,5,5,2,5,4,0,3,1,4,2,1,3,4,0,3,1,3,4,0,3,4,3,9};
/* 6 *///int stimuliArray[] = {4,3,0,4,2,4,1,5,5,1,0,5,0,2,4,1,4,2,4,3,0,4,1,4,0,2,1,2,5,0,5,2,3,1,2,0,1,2,5,3,5,5,9};
int inByte = 0;
int caseCounter = 0;
const int maxCases = 42;

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
void generateCaseArray();


void setup() {
  // put your setup code here, to run once:
  pinMode(cooling, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(motor, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
  //resetAll();
  while (!Serial) {
    ;
  }
  pinMode(interuptButton, INPUT_PULLUP);
  //wait for the button to be pressed before start
  while (digitalRead(interuptButton) == 1) {
    ;
  }
  delay(4000);
}

void loop() {

  if((Serial.available() >= 0) || stimulusActive){ //only proceed if processing is done with its part and ready to receive

    if (!stimulusActive) { //choose new stimulus after last one was handled
      wasInterrupted = false;

      randomNumber = stimuliArray[caseCounter];

      if (randomNumber != 9) {
        caseCounter++;
      } else if (randomNumber == 9){
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
          slowMotorAction();
          break;
        case 3:
          stimulusActive = true;
          ledAction();
          break;
        case 4:
          stimulusActive = true;
          peltierAction();
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
    ;
  }
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
  analogWrite(motor, 1);
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
  startTime = millis();
  while (digitalRead(interuptButton) == 1) {
    ;
  }
  wasInterrupted = true;
}

void slowMotorAction(){
  stimulusActive = true;
  intensity = 60;
  startTime = millis();
  while(intensity >= 0 && digitalRead(interuptButton) == 1){
    analogWrite(motor, intensity);
    delay(wait);
      intensity = min(168, intensity + 1);
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
