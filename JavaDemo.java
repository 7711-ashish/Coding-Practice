import java.io.*;
import java.util.*;
class Mythread extends Thread {
    public void run(){
        for(int i=0;i<10;i++){
            Thread.yield();
            System.out.println("Child Thread");
        }
    }
}
public class JavaDemo {
    public static void main(String[] args) {
        Mythread t1 = new Mythread();
        t1.start();
        for(int i=0;i<10;i++){
            System.out.println("Main Thread");
        }
    }
        
}