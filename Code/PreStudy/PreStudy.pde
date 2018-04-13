import processing.serial.*;
import processing.sound.*;


Serial myPort;
int portNumber;

char[] charData = new char[15];
int charIndex = 0;
int i=0;      
PrintWriter output;
SoundFile soundfile;
long ttp = 0; // time to perception.
long startTime = 0;

void setup() {
 output = createWriter("test.txt");
 soundfile = new SoundFile(this, "sonarcut.mp3");
 for (int i=0; i< Serial.list().length; i++) {
     if(Serial.list()[i].equals("/dev/cu.usbmodem146411")) {
       portNumber = i;
     }
 }
 println(Serial.list());
 
 String portName = Serial.list()[portNumber];
 myPort = new Serial(this, portName, 9600);
 print("Connected to ");
 println(portName);
}

void draw() {
   while (myPort.available() > 0) {
     char readChar = myPort.readChar();
     //print(readChar);
     charData[i] = readChar;
     i++;
     if (readChar == 'x') {
       println(charIndex);
       i = 0;
       println(charData);
       handleInput();
       delay(50);
       myPort.clear();
     }
   }
}

void handleInput(){
  int counter = 0;
  for (int j = 0; j < charData.length; j++){
    if (charData[j] != ' '){
      counter++;
    }
  }
  char[] tempData = new char[counter];
  for(int p = 0; p < counter; p++){
    tempData[p] = charData[p];
  }
  charData = clearBuffer(charData);
  switch (tempData[0]){
    case 'D':
      println("D");
      output.print(tempData[1] + ",");
      int n = 2;
      while(tempData[n] != 'x'){
        if(tempData[n] != 't'){
          output.print(tempData[n]);
        }
        n++;
      }
      output.println();
      output.flush();
      break;
    case 'S':
      println("S");
      soundfile.play();
      startTime = millis();
      break;
    case 'I':
      println("I");
      ttp = millis() - startTime;
      soundfile.stop();
      output.println(5 + "," + ttp);
      output.flush();
      break;
    case 'F':
      println("F - Finished Session");
      output.flush();
      output.close();
      break;
    default: println("Error with Buffer handling");
  }
  
}

char[] clearBuffer(char[] buffer){
  for(int i = 0; i < buffer.length; i++){
    buffer[i] = ' ';
  }
  return buffer;
}