import processing.core.PApplet;
import processing.sound.*;
import processing.serial.*;

public class PreStudyMain extends PApplet{
    public static void main(String[] args){
        PApplet.main("PreStudyMain", args);
    }

    Serial myPort;
    SoundFile file;

    public void settings(){
        size(200, 200);
    }

    public void setup(){
        //String portName = "/dev/cu.usbmodem14521";
        //print(portName);
        //myPort = new Serial(this, portName, 9600);
        file = new SoundFile(this,"~/data/Sonar.mp3");
        file.play();
    }

    public void draw(){
        rect(20, 20, 20, 30);
        fill(20);
    }
}
