# Digitally Controlled DC-DC Buck Converter for Smart Energy Node Applications

![ESP32](https://img.shields.io/badge/ESP32-IoT-blue)
![Power Electronics](https://img.shields.io/badge/Power-Electronics-red)
![Buck Converter](https://img.shields.io/badge/DC--DC-Buck-green)

---

## Overview

This project presents the design and implementation of a digitally controlled DC-DC buck converter using an ESP32 microcontroller for PWM generation and an INA219 sensor for real-time voltage and current monitoring.

The converter steps down a 12V DC input to an adjustable regulated output suitable for smart energy node applications.

---

## Features

- ESP32-based PWM control
- Adjustable duty cycle
- INA219 voltage/current sensing
- Real-time efficiency calculation
- Overcurrent protection
- Serial Plotter visualization
- CCM and DCM analysis
- Experimental performance evaluation
- Smart energy node architecture foundation

---

## Hardware Components

| Component | Specification |
|-----------|--------------|
| ESP32 | ESP32 DevKit |
| MOSFET | IRLZ44N |
| Diode | MBR1045 Schottky |
| Inductor | 150 µH, 4A |
| Capacitor | 220 µF |
| Sensor | INA219 |
| Load | 10Ω Power Resistor |

---

## System Architecture

```plaintext
12V DC → MOSFET → Inductor → Output → Load
                  ↓
               Diode
