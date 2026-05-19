# Hardware Implementation

# Overview

The hardware implementation of the digitally controlled DC-DC buck converter consists of:

- PWM generation using ESP32
- Gate driving using TC4420
- Power switching using MOSFET
- Energy transfer using inductor
- Output filtering using capacitors
- Real-time sensing using INA219

The complete system converts 12V DC input into an adjustable lower DC output voltage.

---

# 1. Power Supply Stage

A 12V DC adapter is used as the input source.

Specifications:
- Voltage: 12V
- Current: 1.5A

The adapter supplies power to:
- Buck converter
- TC4420 gate driver
- Output load

---

# 2. PWM Generation Stage

The ESP32 microcontroller generates PWM signals at:

25kHz switching frequency.

The PWM duty cycle controls the output voltage.

Duty cycle is adjustable through Serial Monitor.

GPIO25 is used as PWM output pin.

---

# 3. Gate Driver Stage

The TC4420 gate driver amplifies the PWM signal from ESP32.

Reason for using TC4420:
- ESP32 output current is insufficient for direct MOSFET driving
- Faster switching
- Reduced switching losses
- Better gate charging and discharging

Connections:
- ESP32 GPIO25 → TC4420 Input
- TC4420 Output → MOSFET Gate

TC4420 operates from 12V supply.

---

# 4. MOSFET Switching Stage

An N-channel MOSFET is used as the switching device.

MOSFET operation:
- ON during PWM HIGH
- OFF during PWM LOW

The MOSFET rapidly switches current through the inductor.

Gate resistor:
100Ω resistor is connected between TC4420 output and MOSFET gate.

Pull-down resistor:
10kΩ resistor connects gate to ground.

Purpose:
- Prevent floating gate
- Ensure stable switching

---

# 5. Inductor Stage

A toroidal power inductor is used.

Specifications:
- 150uH
- 5A rated

Purpose:
- Store energy during ON cycle
- Release energy during OFF cycle
- Smooth current flow

The inductor is connected between:
Switching node and output.

---

# 6. Freewheeling Diode Stage

A fast recovery or Schottky diode is used.

Purpose:
- Provide current path during MOSFET OFF time
- Protect switching stage
- Maintain continuous current flow

Connection:
- Cathode → Switching node
- Anode → Ground

---

# 7. Output Filter Stage

Capacitors are used for output filtering.

Capacitors used:
- 220uF electrolytic capacitors
- 10uF capacitors
- 0.1uF ceramic capacitors

Purpose:
- Reduce output ripple
- Stabilize output voltage
- Improve transient response

---

# 8. Load Stage

A 10Ω 10W resistor is used as resistive load.

Purpose:
- Test converter performance
- Measure voltage regulation
- Analyze efficiency

---

# 9. Sensing Stage

INA219 current sensor module is used.

Measured parameters:
- Output voltage
- Output current
- Output power

The INA219 communicates with ESP32 through I2C interface.

Connections:
- SDA → GPIO21
- SCL → GPIO22

---

# 10. Common Ground

All modules share common ground.

Important grounds:
- ESP32 GND
- TC4420 GND
- MOSFET Source GND
- Adapter GND
- INA219 GND

Without common ground:
- PWM instability occurs
- Incorrect switching occurs
- Converter fails to operate properly

---

# 11. Breadboard Implementation

The prototype is implemented on breadboard.

Important considerations:
- Keep switching wires short
- Place capacitor near output
- Place diode near MOSFET
- Minimize loop area

---

# 12. Hardware Operation Summary

1. ESP32 generates PWM
2. TC4420 amplifies PWM
3. MOSFET switches rapidly
4. Inductor stores/releases energy
5. Capacitors smooth output
6. INA219 monitors parameters
7. Output voltage varies with duty cycle

---

# 13. Experimental Observations

Observed behavior:
- Output voltage increases with duty cycle
- Stable operation achieved
- Converter works under resistive load
- Real-time monitoring successful

---

# 14. Final Prototype

The hardware successfully demonstrates:
- Digital power conversion
- PWM voltage control
- Real-time sensing
- Smart energy node foundation
