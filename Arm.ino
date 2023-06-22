
void arm_init(){
  Base.attach(8);  //port 3 : Servo 1

  Arm1.attach(9);  //port 2 : Servo 2

  Arm2.attach(10); //Port 45: servo 3

  Arm3.attach(11); //Port 46: servo 4
  
  arm_home();
}

void arm_home() {
  Base.write(90);
  Arm1.write(110);
  Arm2.write(180);
  Arm3.write(180);
}
