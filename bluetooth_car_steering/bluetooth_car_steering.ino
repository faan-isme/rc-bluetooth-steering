// ==== PIN DEFINISI ====
// Motor PENGGERAK 
#define L_RPWM 5
#define L_LPWM 6
#define L_ENA 7
#define L_ENB 8

#define R_RPWM 9
#define R_LPWM 10
#define R_ENA 11
#define R_ENB 12

// Motor STEERING
#define STEER_IN1 2   // IN1 L298N
#define STEER_IN2 4   // IN2 L298N
#define STEER_EN 3    // ENA L298N (pakai PWM)

// Potensiometer feedback
#define STEER_POT A0  

// ==== VARIABEL ====
char command;
int pwm = 200;

int steerTarget = 580;      // target posisi
int steerLeftLimit = 320;   // batas kiri
int steerRightLimit = 840;  // batas kanan
int steerStep = 20;         // langkah tiap tekan tombol

void setup() {
  Serial.begin(9600);

  // Motor belakang
  pinMode(L_RPWM, OUTPUT);
  pinMode(L_LPWM, OUTPUT);
  pinMode(L_ENA, OUTPUT);
  pinMode(L_ENB, OUTPUT);

  pinMode(R_RPWM, OUTPUT);
  pinMode(R_LPWM, OUTPUT);
  pinMode(R_ENA, OUTPUT);
  pinMode(R_ENB, OUTPUT);

  digitalWrite(L_ENA, HIGH);
  digitalWrite(L_ENB, HIGH);
  digitalWrite(R_ENA, HIGH);
  digitalWrite(R_ENB, HIGH);

  // Steering
  pinMode(STEER_IN1, OUTPUT);
  pinMode(STEER_IN2, OUTPUT);
  pinMode(STEER_EN, OUTPUT);

  stopMotors();
  centeringSteering();
}

void loop() {
  // Cek apakah ada commad masuk dari hc-05
  if (Serial.available()) {
    command = Serial.read();

    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': stopMotors(); break;
      case '0' ... '9': // fitur khusus di Arduino (GCC extension) yang artinya semua karakter dari '0' sampai '9' akan masuk ke blok ini.
        pwm = (command - '0') * 25; //ASCII conversi
        Serial.print("PWM set to: ");
        Serial.println(pwm);
        break;

      case 'q':
        pwm = 255;
        Serial.println("PWM MAX");
        break;
    }
  }
}


void forward() {
  analogWrite(L_RPWM, pwm);
  analogWrite(L_LPWM, 0);
  analogWrite(R_RPWM, pwm);
  analogWrite(R_LPWM, 0);
}
void backward() {
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, pwm);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, pwm);
}
void stopMotors() {
  analogWrite(L_RPWM, 0);
  analogWrite(L_LPWM, 0);
  analogWrite(R_RPWM, 0);
  analogWrite(R_LPWM, 0);
  digitalWrite(STEER_IN1, LOW);
  digitalWrite(STEER_IN2, LOW);
  analogWrite(STEER_EN, 0);
}

// ==== STEERING CONTROL ====
void centeringSteering() {
  int steerPos = analogRead(STEER_POT);
  if (steerPos < steerTarget) {
    digitalWrite(STEER_IN1, HIGH);
    digitalWrite(STEER_IN2, LOW);
    analogWrite(STEER_EN, 150);
  } else if (steerPos > steerTarget ) {
    digitalWrite(STEER_IN1, LOW);
    digitalWrite(STEER_IN2, HIGH);
    analogWrite(STEER_EN, 150);
  } else {
    digitalWrite(STEER_IN1, LOW);
    digitalWrite(STEER_IN2, LOW);
    analogWrite(STEER_EN, 0);
  }
}

void right() {
  int steerPos = analogRead(STEER_POT);
  if (steerPos < steerRightLimit) {
    // belok kanan
    digitalWrite(STEER_IN1, HIGH);
    digitalWrite(STEER_IN2, LOW);
    analogWrite(STEER_EN, 100);
  } else {
    // sudah di posisi target
    digitalWrite(STEER_IN1, LOW);
    digitalWrite(STEER_IN2, LOW);
    analogWrite(STEER_EN, 0);
  }
}

void left() {
  int steerPos = analogRead(STEER_POT);
  if (steerPos > steerLeftLimit) {
    // belok kiri
    digitalWrite(STEER_IN1, LOW);
    digitalWrite(STEER_IN2, HIGH);
    analogWrite(STEER_EN, 100);
  } else {
    // sudah di posisi target
    digitalWrite(STEER_IN1, LOW);
    digitalWrite(STEER_IN2, LOW);
    analogWrite(STEER_EN, 0);
  }
}
