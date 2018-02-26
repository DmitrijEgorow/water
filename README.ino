  #include <SoftwareSerial.h>
#include <Time.h>
#include <Wire.h>
                 

using namespace std;
int gLedPin = 13;
int gRxPin = 10;
int gTxPin = 11;
//int address=0x05;
int i=0;
int16_t answ[2]  {0, 0};
int16_t m, n;
String str;
char a, b, c, d;
int16_t e[2];

// 0x5, 0x1E, 0x1F, 0xA0, 

SoftwareSerial BTSerial(gRxPin, gTxPin);

void on_request()
  { char l;
    if(Wire.available()){ char l=Wire.read();
    if(l==0x1E)
      {
        //Wire.beginTransmission(0x1E);
        Wire.write(0x1F);
        //Wire.endTransmission();
        return;
      }
    if(l==0xA0){
      //Wire.beginTransmission(0xA0);
        Wire.write("12");
       // Wire.endTransmission();
        return;}
    }
  } 
 

void setup() {
  BTSerial.begin(38400);
  Serial.begin(38400);
  
  //Wire.begin();
  Wire.begin(0x05);
  Wire.onRequest(on_request);

  //Wire.onReceive(receiveEvent);
  //pinMode(12, OUTPUT);
  //delay(500);
}

void loop() {

 
  
  if (Wire.available()) { //BTSerial
    //Wire.write(BTSerial.read());
    Serial.write(BTSerial.read());
    a=Wire.read();
    b = Wire.read();
    c = Wire.read();
    d = Wire.read();
    e[0] = (a-'0')*10+b-'0';
    e[1] = (c-'0')*10+d-'0';
    if ((b!='\n') && (d!='\n') && (c!='\n') && (a!='\n')){
     // Wire.beginTransmission(0xA0);
          Wire.write((const char *)e,4);
       //   Wire.endTransmission();
    Serial.write((const char *)e,4);
      }
  }
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
/*
  if (i==0){

     Wire.beginTransmission(0x1E);

  //Wire.send(0x50);

  Wire.write(0x1F);

  Wire.endTransmission();
  i++;

  //Wire.send();

    
    }
  else{
    Wire.beginTransmission(0xA0);
    //(const char *str)
    Wire.write(const char * answ, 4);
    //Wire.write(const char *str);
    Wire.endTransmission();*/    
/*
  while(Wire.available())    // ведомое устройство может послать меньше, чем запрошено
  { 
    char c = Wire.read();    // принять байт как символ
    Serial.print(c);         // напечатать символ
  }*/

    
   // }

  
  //Wire.requestFrom(address, 1);

  //while (Wire.available()==0);

  //a = Wire.read();
  //a = Wire.receive();
  //Serial.print(a);
  delay(100);

  
}
