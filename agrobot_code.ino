/******************************************* Contributers: Amesh Shrestha, Gavin, Shariar Description: Last Modified: 6/6/2023
********************************************/

#include <Servo.h>
#include <LiquidCrystal_I2C.h> // Library for LCD

char startUpMsg[] = "What is my purpose?"; // start up message

int armhold = 300; //time between arm movements

const int echo[] = { 0, 29, 27, 25, 23 };  //sonar ecopins 
const int trig[] = { 0, 28, 26, 24, 22 };  //sonar triger pins

          //Motor:  0   1  2
const int M_F[] = { 2, 6, 4 };  // Motor Forward Pins
const int M_B[] = { 3, 7, 5 };  // Motor Backwards Pins


double v[] = {0,0,0,70};

Servo Base;
Servo Arm1;
Servo Arm2;
Servo Arm3;  // create servo object to control a servo
// twelve servo objects can be created on most boards

LiquidCrystal_I2C lcd(0x27,20,4); // I2C address 0x27, 16 column and 2 rows

void sonar_init();
void base_init();
void arm_init();


int sonar(int sonarID);
int FrontSonarCollitionDetect(int distance);

void calc_base(const double * movestr);
void move_base(double M0, double M1, double M2);
void BaseStop();

void forward(int distance);
void rotate( int angle);
void left(int distance);
void right(int distance);
void backward(int distance);

void findStock();

void arm_home();

void setup() {
  Serial.begin(9600);

  sonar_init(); // initialize all our sensor pins

  base_init();  // initialize all our motor pins to output 

  arm_init(); // initialize are and set the arm to home position

  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 

  lcd.print(startUpMsg);
  // delay(1000);
  // v[1] = 1;
  // lcd.clear();
  // lcd.print("START");
  // calc_base(v);
  // delay(2000);

}


void loop() {
  v[1] = 1;
  wallAlignment();
  
  // calc_base(v);
  // if(WECsonar(2) < 20) {
  //   v[1] = 0;
  //   calc_base(v);
  //   lcd.clear();
  //   lcd.setCursor(0,0);
  //   lcd.print("Cotton Stock Found!!");
  //   wallAlignment();
  //   delay(2000);
  //   v[1];
  //   calc_base(v);
  //   lcd.clear();
  //   lcd.print("NEXT");    
  //   delay(1000);
  // }
}


