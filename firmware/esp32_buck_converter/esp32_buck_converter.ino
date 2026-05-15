#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

// PWM Configuration
const int pwmPin = 25;
const int pwmChannel = 0;
const int pwmFreq = 25000;
const int pwmResolution = 8;
int dutyCycle = 128; // Default 50%
float Vin = 12.0;
// Protection Threshold
float maxCurrent = 3.0; // 3A limit
void setup() {
  Serial.begin(115200);
  // INA219 Init
  if (!ina219.begin()) {
    Serial.println("INA219 not found!");
    while (1);
  }
  // PWM Setup
  ledcAttach(pwmChannel, pwmFreq, pwmResolution);
  ledcWrite(pwmPin, pwmChannel);
  Serial.println("System Ready");
  Serial.println("Enter Duty Cycle (0–100):");
}

void loop() {

  // ===== SERIAL DUTY CONTROL =====
  if (Serial.available() > 0) {

    String inputString = Serial.readStringUntil('\n');
    inputString.trim();

    int input = inputString.toInt();

    // Accept only valid range
    if (input >= 0 && input <= 100) {

      dutyCycle = map(input, 0, 100, 0, 255);

      Serial.print("New Duty Cycle: ");
      Serial.print(input);
      Serial.println("%");
    }
  }

  // PWM OUTPUT
  ledcWrite(pwmPin, dutyCycle);

  // ===== SENSOR READINGS =====
  float Vout = ina219.getBusVoltage_V();
  float current_A = ina219.getCurrent_mA() / 1000.0;

  float Pout = Vout * current_A;
  float Pin = Vin * current_A;

  float efficiency = 0;

  if (Pin > 0) {
    efficiency = (Pout / Pin) * 100.0;
  }

  // ===== OVERCURRENT PROTECTION =====
  if (current_A > maxCurrent) {

    ledcWrite(pwmPin, 0);

    Serial.println("⚠️ Overcurrent Shutdown");

    while (1);
  }

  // ===== SERIAL MONITOR =====
  Serial.print("Duty: ");
  Serial.print((dutyCycle / 255.0) * 100);
  Serial.print("%  ");

  Serial.print("Vout: ");
  Serial.print(Vout);
  Serial.print(" V  ");

  Serial.print("Current: ");
  Serial.print(current_A);
  Serial.print(" A  ");

  Serial.print("Power: ");
  Serial.print(Pout);
  Serial.print(" W  ");

  Serial.print("Efficiency: ");
  Serial.print(efficiency);
  Serial.println(" %");

  // ===== SERIAL PLOTTER =====
  Serial.print(Vout);
  Serial.print(" ");

  Serial.print(current_A);
  Serial.print(" ");

  Serial.print(Pout);
  Serial.print(" ");

  Serial.println(efficiency);

  delay(500);
}