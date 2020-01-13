#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>  
#define FIREBASE_HOST "stimulation-kit.firebaseio.com"
#define FIREBASE_AUTH "PkeQ3HcCYwKnpWhNTfPiCxlmNOGNTO111IgfiHxC"
#define WIFI_SSID "Home Wifi"
#define WIFI_PASSWORD "homewifi@isa@aafreen72"
int motor_1_pos=16;//D0
int motor_1_neg=5;//D1
int motor_2_pos=4;//D2
int motor_2_neg=0;//D3
void setup() {
  Serial.begin(9600);
  pinMode(motor_1_pos,OUTPUT);
  pinMode(motor_1_neg,OUTPUT);
  pinMode(motor_2_pos,OUTPUT);
  pinMode(motor_2_neg,OUTPUT);
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


void loop() {
  // get value 
  int forward = Firebase.getInt("forward");
  int backward = Firebase.getInt("backward");
  int left = Firebase.getInt("left");
  int right = Firebase.getInt("right");
  int stop_car = Firebase.getInt("stop");
  Serial.println(forward);
  Serial.println(backward);
  Serial.println(left);
  Serial.println(right);
  Serial.println(stop_car);
  if(forward==1){
    digitalWrite(motor_1_pos,HIGH);
     digitalWrite(motor_1_neg,LOW);
     digitalWrite(motor_2_pos,HIGH);
      digitalWrite(motor_2_neg,LOW);
  }
  if(backward==1){
    digitalWrite(motor_1_pos,LOW);
     digitalWrite(motor_1_neg,HIGH);
     digitalWrite(motor_2_pos,LOW);
      digitalWrite(motor_2_neg,HIGH);
  }
  if(forward==1 && left==1){
     digitalWrite(motor_1_pos,HIGH);
     digitalWrite(motor_1_neg,LOW);
     digitalWrite(motor_2_pos,LOW);
      digitalWrite(motor_2_neg,LOW);
  }
   if(forward==1 && right==1){
     digitalWrite(motor_1_pos,LOW);
     digitalWrite(motor_1_neg,LOW);
     digitalWrite(motor_2_pos,HIGH);
      digitalWrite(motor_2_neg,LOW);
  }
  if(stop_car==1){
     digitalWrite(motor_1_pos,LOW);
     digitalWrite(motor_1_neg,LOW);
     digitalWrite(motor_2_pos,LOW);
      digitalWrite(motor_2_neg,LOW);
  }




  
}
