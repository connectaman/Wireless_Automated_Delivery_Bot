#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>  
#define FIREBASE_HOST "authentication-3bb95.firebaseio.com"
#define FIREBASE_AUTH "mfyopyVV8tZIm3QhxlY0v55JwkF9AQHEFEhLrwJE"
#define WIFI_SSID "Home Wifi"
#define WIFI_PASSWORD "homewifi@isa@aafreen72"
int digit1 = 5; //D1   8
int digit2 = 4;  //D2   4
int digit3 = 0; //D3   2
int digit4 = 2; // D4     1

void setup() {
  Serial.begin(9600);
  pinMode(digit1,OUTPUT);
  pinMode(digit2,OUTPUT);
  pinMode(digit3,OUTPUT);
  pinMode(digit4,OUTPUT);
//  pinMode(int_read,OUTPUT);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop() {
 
  
  int uid = Firebase.getInt("uid");
  Serial.println(uid);
   int otp = Firebase.getInt("otp");
  Serial.println(otp);
  int otp_data = otp;
  int rem4 = otp_data%10;
  otp_data/=10;
  int rem3 = otp_data%10;
  otp_data/=10;
  int rem2 = otp_data%10;
  otp_data/=10;
  int rem1 = otp_data%10;
  otp_data/=10;
  analogWrite(digit1,rem1);
  analogWrite(digit2,rem2);
  analogWrite(digit3,rem3);
  analogWrite(digit4,rem4);
//  while(uid!=0){
//    int rem = uid%10;
//    uid=uid/10;
//    digitalWrite(int_read,HIGH);
//    switch(rem){
//      case 1:
//        digitalWrite(digit1,LOW);
//        digitalWrite(digit2,LOW);
//        digitalWrite(digit3,LOW);
//        digitalWrite(digit4,HIGH);
//      break;
//      case 2:
//        digitalWrite(digit1,LOW);
//        digitalWrite(digit2,LOW);
//        digitalWrite(digit3,HIGH);
//        digitalWrite(digit4,LOW);
//      break;
//      case 3:
//        digitalWrite(digit1,LOW);
//        digitalWrite(digit2,LOW);
//        digitalWrite(digit3,HIGH);
//        digitalWrite(digit4,HIGH);
//      break;
//      case 4:
//        digitalWrite(digit1,LOW);
//        digitalWrite(digit2,HIGH);
//        digitalWrite(digit3,LOW);
//        digitalWrite(digit4,LOW);
//      break;
//      case 5:
//        digitalWrite(digit1,LOW);
//        digitalWrite(digit2,HIGH);
//        digitalWrite(digit3,LOW);
//        digitalWrite(digit4,HIGH);
//      break;
//      case 6:
//        digitalWrite(digit1,LOW);
//        digitalWrite(digit2,HIGH);
//        digitalWrite(digit3,HIGH);
//        digitalWrite(digit4,LOW);
//      break;
//      case 7:
//        digitalWrite(digit1,LOW);
//        digitalWrite(digit2,HIGH);
//        digitalWrite(digit3,HIGH);
//        digitalWrite(digit4,HIGH);
//      break;
//      case 8:
//        digitalWrite(digit1,HIGH);
//        digitalWrite(digit2,LOW);
//        digitalWrite(digit3,LOW);
//        digitalWrite(digit4,LOW);
//      break;
//      case 9:
//        digitalWrite(digit1,HIGH);
//        digitalWrite(digit2,LOW);
//        digitalWrite(digit3,LOW);
//        digitalWrite(digit4,HIGH);
//      break;
//    }
//    delay(500);
//    digitalWrite(int_read,LOW);
//  }
 
}
