import processing.sound.*;

SoundFile file;
long time = 0;
long startTime = 0;

void setup(){
  file = new SoundFile(this, "sonar.mp3");
}

void draw(){
 
}

void mousePressed(){
  
  file.play();
  startTime = millis();
 delay((int)(file.duration()*1000));
  time = millis() - startTime;
  println(time + "  " + file.duration());
}