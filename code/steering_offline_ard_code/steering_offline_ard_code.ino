const int steering_pot=A1;
const int accelatration_pot=A2;
//const int SW_pin = 2; // digital pin connected to switch output
//const int X_pin = 0; // analog pin connected to X output
int forward = 3;
int backward = 4;
int left = 5;
int right = 6;
int stop_car = 7;
//int axis_camera =8;
//int int_sl=3;
//int int_sr=4;
//int int_sf=5;
//int int_af=6;
//int int_ab=7;
//int int_as=8;
//int int_switch=9;
//int int_axisl=10;
//int int_axisr=11;
void setup() {
pinMode(steering_pot,INPUT);
pinMode(accelatration_pot,INPUT);
//pinMode(X_pin,INPUT);
//pinMode(SW_pin, INPUT);
pinMode(forward,OUTPUT);
pinMode(backward,OUTPUT);
pinMode(left,OUTPUT);
pinMode(right,OUTPUT);
pinMode(stop_car,OUTPUT);
//pinMode(int_sl,OUTPUT);
//pinMode(int_sr,OUTPUT);
//pinMode(int_sf,OUTPUT);
//pinMode(int_af,OUTPUT);
//pinMode(int_ab,OUTPUT);
//pinMode(int_as,OUTPUT);
//pinMode(int_switch,OUTPUT);
//pinMode(int_axisl,OUTPUT);
//pinMode(int_axisr,OUTPUT);
//digitalWrite(SW_pin, HIGH);
Serial.begin(9600);
}

void loop() {
    int steering_value = analogRead(steering_pot);
    int steering_mapp_left=(steering_value<340)?1:0;
    int steering_mapp_right=(steering_value>680)?1:0;
    int steering_mapp_forward=(steering_value>340 && steering_value<680)?1:0;
  Serial.println("----------- STEERING VALUES ----------");
  Serial.println(steering_value);
  Serial.print(steering_mapp_left);Serial.print("    : LEFT");Serial.println();
  Serial.print(steering_mapp_right);Serial.print("    : RIGHT");Serial.println();
  Serial.print(steering_mapp_forward);Serial.print("    : FORWARD");Serial.println();
  Serial.println("-------------------------------------------");
    int acc_value = analogRead(accelatration_pot);
    int acc_map_forward=(acc_value<340)?1:0;
    int acc_map_back=(acc_value>680)?1:0;
    int acc_map_stop=(acc_value>340 && acc_value<680)?1:0;
  Serial.println("----------- ACCELARATION VALUES ----------");
  Serial.println(steering_value);
  Serial.print(acc_map_forward);Serial.print("    : FORWARD");Serial.println();
  Serial.print(acc_map_back);Serial.print("    : BACK");Serial.println();
  Serial.print(acc_map_stop);Serial.print("    : STOP");Serial.println();
  Serial.println("-------------------------------------------");
  Serial.println("X-axis: ");
//  int x_axis_value = analogRead(X_pin);
//  int switch_value = digitalRead(SW_pin);
  Serial.println("------- RESET BACK TO NORMAL VIEW----------");
  //Serial.print(switch_value);Serial.print("RESET");
  Serial.println("-------------------------------------------");
  //  int x_axis_map_left = (x_axis_value<495)?1:0;
  //  int x_axis_map_right = (x_axis_value>500)?1:0;
  if(acc_map_forward==1){    // only forward
    digitalWrite(forward,HIGH);
    digitalWrite(left,LOW);
    digitalWrite(right,LOW);
    digitalWrite(backward,LOW);
    digitalWrite(stop_car,LOW);
    
  }
  if(acc_map_back==1){   //only backward
    digitalWrite(forward,LOW);
    digitalWrite(left,LOW);
    digitalWrite(right,LOW);
    digitalWrite(backward,HIGH);
    digitalWrite(stop_car,LOW);
  }
  if(acc_map_forward==1 && steering_mapp_left==1){
    digitalWrite(forward,HIGH);
    digitalWrite(left,HIGH);
    digitalWrite(right,LOW);
    digitalWrite(backward,LOW);
    digitalWrite(stop_car,LOW);
  }
  if(acc_map_forward==1 && steering_mapp_right==1){
    digitalWrite(right,HIGH);
    digitalWrite(left,LOW);
    digitalWrite(forward,HIGH);
    digitalWrite(backward,LOW);
    digitalWrite(stop_car,LOW);
  }
  if(acc_map_stop==1){
    digitalWrite(stop_car,HIGH);
    digitalWrite(right,LOW);
    digitalWrite(left,LOW);
    digitalWrite(backward,LOW);
    digitalWrite(forward,LOW);
  }

//  digitalWrite(int_sl,steering_mapp_left);
//  digitalWrite(int_sr,steering_mapp_right);
//  digitalWrite(int_sf,steering_mapp_forward);
//  digitalWrite(int_as,acc_map_stop);
//  digitalWrite(int_ab,acc_map_back);
//  digitalWrite(int_af,acc_map_forward);
//  digitalWrite(int_switch,switch_value);
//  digitalWrite(int_axisl,x_axis_map_left);
//  digitalWrite(int_axisr,x_axis_map_right);
//  Serial.print(x_axis_map_left);Serial.print(" ");Serial.print(x_axis_map_right);
delay(2000);
  
  
}
