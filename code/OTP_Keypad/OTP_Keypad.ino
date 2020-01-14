#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
int digit1 = A0;
int digit2 = A1;  
int digit3 = A2; 
int digit4 = A3; 
char otp[10];
int count = 0;
int len = 4;
int equal = 0;
int chances = 0;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
   Serial.begin(9600);
  pinMode(digit1,INPUT);
  pinMode(digit2,INPUT);
  pinMode(digit3,INPUT);
  pinMode(digit4,INPUT);
}
void loop(){
  char key = keypad.getKey();
  if (key){
    Serial.println(key);
    if(key=='D'){
      
  }
  if(key=='A' || key == 'B' || key=='C' || key=='#' || key=='*'){
    count = 0;
  }else if(key=='D'){
    chances++;
    int result = checkOTP();
    Serial.print("Result:");Serial.println(result);
    if(result == 1){
      equal = 0;
      count=0;
    }

  }
  else{
     otp[count] = key;
      count++;
  }
  }

//  if(count==len){
//    for(int i=0;i<len;i++){
//    Serial.println(otp[i]);
//  }
  //3828
//  char digit1 = otp[0];
//  char digit2 = otp[1];
//  char digit3 = otp[2];
//  char digit4 = otp[3];
//  Serial.println();
//  Serial.print("Final OTp in int  :");Serial.print(digit1);Serial.print(int(digit2));Serial.print(int(digit3));Serial.print(int(digit4));Serial.println();  
//  //while(1){}
//  int result = checkOTP();
//  Serial.print("Result:");Serial.println(result);
//  while(1){}
//  }

  
  
  
//  int otp = 0;
//  int count = 0;
//  if(key=='A'){
//    char digit1 = keypad.getKey();
//     char digit2 = keypad.getKey();
//      char digit3 = keypad.getKey();
//       char digit4 = keypad.getKey();
//       char end_char =  keypad.getKey();
//       if(end_char=='D'){
//         Serial.println();
//    Serial.print(digit1);Serial.print(digit3);Serial.print(digit3);Serial.print(digit4);
//    Serial.println();
//   while(1){}
//       }
//  }

  

  
 
}

int checkOTP(){
   char *otps[] = {"0316","5764","4382","2838","2412","3987","1972","1172","4693","3214","5111","3531","7314","2912","5825","9717","6437","4075","0771","4202"};
   for(int i=0;i<20;i++){
    for(int j=0;j<4;j++){
        Serial.println(otps[i][j]);
        Serial.println(otp[j]);
      if(otp[j] == otps[i][j]){
          equal++;
      }
    }
//    Serial.print("eqp");Serial.print(equal);
//    Serial.println();
     if(equal==4){
      //equal = 0;
    return 1;
   }
   }
   return 0;
}
