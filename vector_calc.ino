
void calc_base(const double* movestr) {
  double M0 = 0, M1 = 0, M2 = 0;

  // Components:       x      y     w
  double m0c[] = { -0.67, 0, 0.33 };
  double m1c[] = { 0.33, -0.58, 0.33 };
  double m2c[] = { 0.33, 0.58, 0.33 };

  /*  Multiply each motor component by the desired
      overall vector component. Add each product to
      each motor power to find the resulting vector. */
  for (int i = 0; i <= 2; i++) {
    M0 += m0c[i] * movestr[i];
    M1 += m1c[i] * movestr[i];
    M2 += m2c[i] * movestr[i];
  }

  //  Multiply by speed
  M0 *= movestr[3];
  M1 *= movestr[3];
  M2 *= movestr[3];


  move_base(M0, M1, M2);
}

void wallAlignment() {
  while (WECsonar(1) != WECsonar(3)) {
    int delD = WECsonar(1) - WECsonar(3);

    if (delD > 1) {
      v[2] = 1;
    } else if (delD < -1) {
      v[2] = -1;
    }
    calc_base(v);
  }
  v[2] = 0;
  calc_base(v);
}

// void wallAlignmentwithDistance( int wallDistance ) {

//   int aligned = 0;
//   if (aligned) {
//     if (sonar(1) < wallDistance) {

//     }
//   }

// }