#include<SoftwareSerial.h>

SoftwareSerial remote(2, 3); // RX | TX //connecting bluetooth module  

#define lm1 6 // leftmotor
#define lm2 7 // leftmotor
#define rm1 4 // rightmotor
#define rm2 5 // rightmotor

char val;
 
void setup()
{
  remote.begin(9600); // starting bluetooth module
  pinMode(lm1, OUTPUT);// invoking or setting leftmotor 
  pinMode(lm2, OUTPUT);// invoking or setting leftmotor 
  pinMode(rm1, OUTPUT);// invoking or setting rightmotor 
  pinMode(rm2, OUTPUT);// invoking or setting rightmotor 
  //remote.println("Connecting to bluetooth");
  //a random text to bluetooth device
}
 
void loop()
{ 
   if(remote.available()>0) //checking bluetooth device
   {
    val = remote.read(); // reading data from bluetooth device
   }
   switch(val){
    case 'f': fwd(); //moves forward when f is pressed
               break;
    case 'b': bwd(); // moves backward when b is pressed
               break;
           
    case 'l': left();// moves left when l is pressed
               break;
    case 'r': right();// moves right when r is pressed
               break;
    case 's': 
    default:  stp(); // stops when s or other than any alphabet is pressed 
               break;
   }
}

void fwd() // forward movement of motor
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}

void bwd() // backward movement of motor
{
  digitalWrite(lm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,HIGH);
  digitalWrite(rm1,LOW);
}

void left() // left movement of motor
{
  digitalWrite(lm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}


void right()//right movement of motor
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm2,HIGH);
  digitalWrite(rm1,LOW);
}
void stp()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(rm1,LOW);
}
