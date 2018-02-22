int green = 11;
int red = 10;
int blue = 9;
int motor = 6;
int cooling = 13;
int wait = 50;
int intensity = 0;
bool up = true;
char serial;


void setup() {
  // put your setup code here, to run once:
  pinMode(cooling, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600);
}

void greenPulse(){
  intensity = 0;
  up = true;
  while(intensity >= 0){
    analogWrite(green, intensity);
    delay(wait);
    if (up){
      intensity += 15;
    }
    if (!up) {
      intensity -= 15;
    }
   
    if (intensity >= 255){
      up = false;
    } 
  }
}

void loop() {
  while( Serial.available()){
    serial = Serial.read();
    Serial.println(serial);
  }
  // put your main code here, to run repeatedly:
  /*digitalWrite(13, HIGH);
  delay(5000);
  digitalWrite(13, LOW);
  delay(5000);*/
  if (serial == 'H'){
  greenPulse();
  }
}

