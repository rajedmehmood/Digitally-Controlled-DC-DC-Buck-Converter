# Digitally Controlled DC-DC Buck Converter for Smart Energy Node Applications

![ESP32](https://img.shields.io/badge/ESP32-IoT-blue)
![Power Electronics](https://img.shields.io/badge/Power-Electronics-red)
![Buck Converter](https://img.shields.io/badge/DC--DC-Buck-green)

---

## Overview

This project presents the design and implementation of a digitally controlled DC-DC buck converter using an ESP32 microcontroller for PWM generation and a TC4420 gate driver, and an INA219 sensor for real-time voltage and current monitoring.

The converter steps down a 12V DC input to an adjustable regulated output suitable for smart energy node applications.

---

## Features

- ESP32 PWM generation
- TC4420 MOSFET gate driver
- Adjustable duty cycle
- INA219 voltage/current sensing
- Real-time monitoring
- Efficiency calculation
- Overcurrent protection
- Serial Plotter graphs
- Smart energy node architecture foundation

---

## Hardware Components

| Component | Specification |
|-----------|--------------|
| ESP32 | ESP32 DevKit |
| MOSFET | MTA30N06HD |
| Gate Driver | TC4420 |
| Diode | SR1645 Schottky |
| Toroidal Inductor | 150 µH, 5A |
| Capacitors | 220,10,0.1 µF |
| Sensor | INA219 |
| Resistor | 100, 10k ohm |
| Load | 10Ω Power Resistor |
| Power Adapter | 12V, 1.5A |

---

## System Architecture

```plaintext
12V DC → TC4420 → MOSFET → Inductor → Output → Load
                          ↓
                        Diode
```

---

## Buck Converter Equation

- Vout = D × Vin

Where:
- Vout = Output Voltage
- D = Duty Cycle
- Vin = Input Voltage

---

## PWM Control

The ESP32 generates a 25 kHz PWM signal to control the MOSFET switching.

---

## Protection Features

- Hardware Fuse Protection
- Software Overcurrent Protection
- Thermal Considerations
- Decoupling Capacitors

---

## Experimental Analysis

The following characteristics are evaluated:

- Duty Cycle vs Output Voltage
- Efficiency vs Load
- Ripple Voltage
- Thermal performance

---

## Applications

- Smart energy systems
- Power electronics education
- IoT energy nodes
- Embedded power systems
  
---

## Software Features

- Real-time monitoring
- Serial Plotter graphs
- Adjustable duty cycle through serial monitor
- Power calculation
- Efficiency estimation

---

## Upload Instructions

- Install ESP32 Board Package
- Install Adafruit INA219 Library
- Select ESP32 Dev Module
- Upload firmware

---

## Expected Results

| Duty Cycle | Expected Output |
|-----------|--------------|
| 30% | 3.6V |
| 50% | 6V |
| 70% | 8.4V |

---

## Future Work

- Closed-loop PID control
- IoT cloud monitoring
- AI-based fault prediction
- Smart Grid integration
- GridGuardian architecture implementation

---

## Authors

- Rajed Mehmood (2023-EE-400)
- Abdul Rafay Nadeem (2023-EE-410)
- M. Suleman Fazal (2023-EE-428)
- M. Meer Hamza (2023-EE-436)

Department of Electrical, Electronics and Telecommunication Engineering, UET Lahore Faisalabad Campus
