#include <Arduino.h>
#include <IRremote.h>

int n = 0;
int x = 0;
const int RECV_PIN =2;
const int redPin = 3;
const int yellowPin = 4;
const int greenPin = 5;
int in1 = 6; 
int in2 = 7; 
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}
//Before starting the loop you should create functions type "void" to control the driver's pins
//Here I created two functions, the first one turns a motor to a direction (you can change it by switching LOW and HIGH
//and the second one to stop the motor

  void verde(){  
       
    // estos indican cuando se prende el electro
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(greenPin, HIGH);
    delay(2000);
    digitalWrite(greenPin, LOW);
    while (x<3){
      delay (500);
      digitalWrite(greenPin, HIGH);
      delay(500);
      digitalWrite(greenPin, LOW);
      x++;
          
      }
    x = 0;     
  }       

  void yellow(){
    digitalWrite(yellowPin, HIGH);
    delay(3000);
    digitalWrite(yellowPin, LOW);
    delay (500);
    digitalWrite(yellowPin, HIGH);
    delay(500);
    digitalWrite(yellowPin, LOW);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }

  void red(){
    digitalWrite(redPin, HIGH);
    delay(3000);
    digitalWrite(redPin, LOW);
  }

void loop() {
  if (irrecv.decode(&results)){

        switch(results.value){
       
        while (n<5){
      case 0xFFFFFFFF: //Keypad button "power"
      verde(); //in the loop we use the function to turn the motor for 3s and stop it for 2s
      delay(100);
      yellow();
      delay(100);
      red();
      n++;

    }
    n =0;
        }
        irrecv.resume(); 
        }
        }
    
