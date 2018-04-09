
const int red = 11;
const int motor = 9;
const int cooling = 13;
const int interuptButton = 7;
int pinArray[] = {11, 10, 13, 7};

void setup() {
  // put your setup code here, to run once:
  pinMode(cooling, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(motor, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(red, 255);
  analogWrite(motor, 168);
  digitalWrite(cooling, HIGH);
  delay(5000);

  analogWrite(red, 0);
  analogWrite(motor, 0);
  digitalWrite(cooling, LOW);
  delay(4000);
}
