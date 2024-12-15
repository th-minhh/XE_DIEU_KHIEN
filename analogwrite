#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <analogWrite.h>

// Right motor (Motor A)
int AIN1 = 16; // Chân điều khiển chiều quay
int AIN2 = 17; // Chân điều khiển chiều quay
int PWMA = 22; // Chân PWM điều khiển tốc độ

// Left motor (Motor B)
int BIN1 = 18; // Chân điều khiển chiều quay
int BIN2 = 19; // Chân điều khiển chiều quay
int PWMB = 23; // Chân PWM điều khiển tốc độ

// Standby pin (STBY)
int STBY = 25; // Chân Standby

#define MAX_MOTOR_SPEED 255

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  // Điều khiển động cơ phải
  if (rightMotorSpeed < 0) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);    
  } else if (rightMotorSpeed > 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);      
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);      
  }

  // Điều khiển động cơ trái
  if (leftMotorSpeed < 0) {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);    
  } else if (leftMotorSpeed > 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);      
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);      
  }

  // Điều khiển PWM cho động cơ
  analogWrite(PWMA, abs(rightMotorSpeed));
  analogWrite(PWMB, abs(leftMotorSpeed));  
}

void setUpPinModes() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(STBY, OUTPUT); // Set STBY pin as output

  // Set STBY pin LOW to enable motor operation
  digitalWrite(STBY, LOW);

  rotateMotor(0, 0);  // Initialize motors to stop
}

void setup() {
  setUpPinModes();
  Dabble.begin("MyBluetoothCar");  // Khởi tạo kết nối Bluetooth
}

void loop() {
  int rightMotorSpeed = 0;
  int leftMotorSpeed = 0;
  Dabble.processInput();

  if (GamePad.isUpPressed()) {
    rightMotorSpeed = MAX_MOTOR_SPEED;
    leftMotorSpeed = MAX_MOTOR_SPEED;
  }

  if (GamePad.isDownPressed()) {
    rightMotorSpeed = -MAX_MOTOR_SPEED;
    leftMotorSpeed = -MAX_MOTOR_SPEED;
  }

  if (GamePad.isLeftPressed()) {
    rightMotorSpeed = MAX_MOTOR_SPEED;
    leftMotorSpeed = -MAX_MOTOR_SPEED;
  }

  if (GamePad.isRightPressed()) {
    rightMotorSpeed = -MAX_MOTOR_SPEED;
    leftMotorSpeed = MAX_MOTOR_SPEED;
  }

  rotateMotor(rightMotorSpeed, leftMotorSpeed);
}
