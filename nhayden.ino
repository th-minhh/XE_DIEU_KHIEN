#include <DabbleESP32.h>

// Chân LED
#define LED_PIN 23

void setup() {
  // Cài đặt chân LED là OUTPUT
  pinMode(LED_PIN, OUTPUT);

  // Bắt đầu giao tiếp Bluetooth
  Dabble.begin("ESP32_LED_Control"); // Tên BLE hiển thị trên Dabble
}

void loop() {
  // Xử lý các tín hiệu từ Dabble
  Dabble.processInput();

  // Điều khiển LED qua nút "Gamepad" trên Dabble
  if (GamePad.isPressed(1)) { // Nút A
    digitalWrite(LED_PIN, HIGH); // Bật LED
  } 
  else if (GamePad.isPressed(2)) { // Nút B
    digitalWrite(LED_PIN, LOW); // Tắt LED
  }
}