#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>  
#define FIREBASE_HOST "stimulation-kit.firebaseio.com"
#define FIREBASE_AUTH "PkeQ3HcCYwKnpWhNTfPiCxlmNOGNTO111IgfiHxC"
#define WIFI_SSID "Home Wifi"
#define WIFI_PASSWORD "homewifi@isa@aafreen72"
//int int_sl=16;  //D0
//int int_sr=5;   //D1
//int int_sf=4;   //D2
//int int_af=0;   //D3
////int int_ab=2;    //D4
//int int_as=14;   //D5
//int int_switch=12;  //D6
//int int_axisl=13;  //D7
//int int_axisr=15;  //D8
int forward = 0;  //D3
int backward = 14; //D5
int left = 12; //D6
int right = 13; //D7
int stop_car = 15; //D8
void setup() {
//  pinMode(int_sl,INPUT);
//  pinMode(int_sr,INPUT);
//  pinMode(int_sf,INPUT);
//  pinMode(int_af,INPUT);
//  pinMode(int_ab,INPUT);
//  pinMode(int_as,INPUT);
//  pinMode(int_switch,INPUT);
//  pinMode(int_axisl,INPUT);
//  pinMode(int_axisr,INPUT);
pinMode(forward,INPUT);
pinMode(backward,INPUT);
pinMode(right,INPUT);
pinMode(left,INPUT);
pinMode(stop_car,INPUT);
  Serial.begin(9600);
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
//int steering_map_left; 
//int steering_map_right;
//int steering_map_forward;
//int acc_map_stop;
//int acc_map_back;
//int acc_map_forward;
//int switch_value;
//int x_axis_map_left;
//int x_axis_map_right;
void loop() {
  // set value
    int int_forward = digitalRead(forward);
    int int_backward = digitalRead(backward);
    int int_left = digitalRead(left);
    int int_right = digitalRead(right);
    int int_stop = digitalRead(stop_car);
//  steering_map_left = digitalRead(int_sl);
//  steering_map_right = digitalRead(int_sr);
//  steering_map_forward = digitalRead(int_sf);
//  acc_map_stop = digitalRead(int_as);
//  acc_map_back = digitalRead(int_ab);
//  acc_map_forward = digitalRead(int_af);
//  switch_value = digitalRead(int_switch);
//  x_axis_map_left = digitalRead(int_axisl);
//  x_axis_map_right = digitalRead(int_axisr);
//  Serial.println("----------- STEERING VALUES ----------");
//  Serial.print(steering_map_left);Serial.print("    : LEFT");Serial.println();
//  Serial.print(steering_map_right);Serial.print("    : RIGHT");Serial.println();
//  Serial.print(steering_map_forward);Serial.print("    : FORWARD");Serial.println();
//  Serial.println("-------------------------------------------");
//  Serial.println("----------- ACCELARATION VALUES ----------");
//  Serial.print(acc_map_forward);Serial.print("    : FORWARD");Serial.println();
//  Serial.print(acc_map_back);Serial.print("    : BACK");Serial.println();
//  Serial.print(acc_map_stop);Serial.print("    : STOP");Serial.println();
//  Serial.println("-------------------------------------------");
//  Serial.println("------- RESET BACK TO NORMAL VIEW----------");
//  Serial.print(switch_value);Serial.print("RESET");
//  Serial.println("-------------------------------------------");
//  Serial.print(x_axis_map_left);Serial.print(" ");Serial.print(x_axis_map_right);
  Firebase.setInt("forward",int_forward);
  Firebase.setInt("backward",int_backward);
  Firebase.setInt("left",int_left);
  Firebase.setInt("right",int_right);
  Firebase.setInt("stop",int_stop);
//  Firebase.setInt("steering_map_left",steering_map_left);
//  Firebase.setInt("steering_map_right",steering_map_right);
//  Firebase.setInt("steering_map_forward",steering_map_forward);
//  Firebase.setInt("acc_map_stop",acc_map_stop);
//  Firebase.setInt("acc_map_back",acc_map_back);
//  Firebase.setInt("acc_map_forward",acc_map_forward);
//  Firebase.setInt("switch_value",switch_value);
//  Firebase.setInt("x_axis_map_left",x_axis_map_left);
//  Firebase.setInt("x_axis_map_right",x_axis_map_right);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
}
