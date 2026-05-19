#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

const int pwmPin = 25;

const int pwmFreq = 25000;
const int pwmResolution = 8;

int dutyPercent = 30;
int dutyValue = 76;

float Vin = 12.0;

float maxCurrent = 1.2;

float Vout = 0;
float current_A = 0;

float powerOut = 0;
float powerIn = 0;

float efficiency = 0;

void setup() {

  Serial.begin(115200);

  ledcAttach(pwmPin, pwmFreq, pwmResolution);

  ledcWrite(pwmPin, dutyValue);

  if (!ina219.begin()) {

    Serial.println("INA219 NOT FOUND");

    while (1);
  }

  Serial.println("SYSTEM READY");
}

void loop() {

  if (Serial.available()) {

    String input = Serial.readStringUntil('\n');

    input.trim();

    int newDuty = input.toInt();

    if (newDuty >= 0 && newDuty <= 90) {

      dutyPercent = newDuty;

      dutyValue = map(dutyPercent, 0, 100, 0, 255);

      ledcWrite(pwmPin, dutyValue);

      Serial.print("Duty Updated: ");
      Serial.println(dutyPercent);
    }
  }

  ledcWrite(pwmPin, dutyValue);

  Vout = ina219.getBusVoltage_V();

  current_A = ina219.getCurrent_mA() / 1000.0;

  powerOut = Vout * current_A;

  powerIn = Vin * current_A;

  if (powerIn > 0.01) {

    efficiency = (powerOut / powerIn) * 100.0;
  }

  if (current_A > maxCurrent) {

    ledcWrite(pwmPin, 0);

    Serial.println("OVERCURRENT");

    while (1);
  }

  Serial.print("Voltage: ");
  Serial.print(Vout);

  Serial.print(" Current: ");
  Serial.print(current_A);

  Serial.print(" Power: ");
  Serial.print(powerOut);

  Serial.print(" Efficiency: ");
  Serial.println(efficiency);

  Serial.print(Vout);
  Serial.print(" ");

  Serial.print(current_A);
  Serial.print(" ");

  Serial.print(powerOut);
  Serial.print(" ");

  Serial.println(efficiency);

  delay(500);
}
