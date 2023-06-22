void base_init() {
  for (int i = 0; i < 4; i++) {

    pinMode(M_F[i], OUTPUT);
    digitalWrite(M_F[i], LOW);

    pinMode(M_B[i], OUTPUT);
    digitalWrite(M_B[i], LOW);
  }
}

void move_base(double M0, double M1, double M2) {
  // Serial.print(M0);
  // Serial.print(":");
  // Serial.print(M1);
  // Serial.print(":");
  // Serial.println(M2);

  if (M0 >= 0) {
    analogWrite(M_B[0], 0);
    analogWrite(M_F[0], M0);
  } else {
    analogWrite(M_F[0], 0);
    analogWrite(M_B[0], M0 * -1);
  }
  if (M1 >= 0) {
    analogWrite(M_B[1], 0);
    analogWrite(M_F[1], M1);
  } else {
    analogWrite(M_F[1], 0);
    analogWrite(M_B[1], M1 * -1);
  }
  if (M2 >= 0) {
    analogWrite(M_B[2], 0);
    analogWrite(M_F[2], M2);
  }

    else {
      analogWrite(M_F[2], 0);
      analogWrite(M_B[2], M2 * -1);
    }
  }

  void BaseStop() {
    for (int i = 0; i < 4; i++) {
      digitalWrite(M_F[i], LOW);
      digitalWrite(M_B[i], LOW);
    }
  }

  void forward(int distance) {
    double a[] = { 0, 1, 0, 70 };
    calc_base(a);
  }

  void rotate(int angle) {
    double a[] = { 0, 0, 1, 200 };
    calc_base(a);
  }

  void left(int distance) {
    double a[] = { 1, 0, 0, 200 };
    calc_base(a);
  }

  void right(int distance) {
    double a[] = { -1, 0, 0, 200 };
    calc_base(a);
  }

  void backward(int distance) {
    double a[] = { 0, -1, 0, 200 };
    calc_base(a);
  }
