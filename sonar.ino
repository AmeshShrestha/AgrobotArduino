void sonar_init() {
  for (int i = 1; i < 5; i++) {
    pinMode(trig[i], OUTPUT);
    pinMode(echo[i], INPUT);
  }
}

int sonar(int sonarID) {

  static int previousdistance[] = {0,0,0,0,0};
  long duration;

  digitalWrite(trig[sonarID], LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig[sonarID], HIGH);
  delayMicroseconds(10);
  digitalWrite(trig[sonarID], LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo[sonarID], HIGH);
  // Calculating the distance
  float newdistance = duration * 0.034 / 2 ;

  // removes any large changes to 
  if(newdistance> (previousdistance[sonarID]+50)){
    return previousdistance[sonarID];
  }
  else {
    previousdistance[sonarID] = newdistance;
  }
  return newdistance;

}

int WECsonar(int sonarID) {

  long duration;

  digitalWrite(trig[sonarID], LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig[sonarID], HIGH);
  delayMicroseconds(10);
  digitalWrite(trig[sonarID], LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo[sonarID], HIGH);
  // Calculating the distance
  
  return (duration * 0.034 / 2);

}

int FrontSonarCollitionDetect(int distance) {

    if (sonar(4) < distance) {
      return 1;
    }
    return 0;

}


