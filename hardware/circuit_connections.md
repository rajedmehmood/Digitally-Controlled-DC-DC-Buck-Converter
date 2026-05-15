## ESP32 PWM Connection

| ESP32 Pin | Connection |
|----------|-----------|
| GPIO25 | MOSFET Gate |
| GND | Circuit Ground |

## INA219 Connection

| INA219 | ESP32 |
|--------|------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

## MOSFET Connection

| MOSFET Pin | Connection |
|-----------|-----------|
| Gate | PWM via 100Ω resistor |
| Drain | Input Supply |
| Source | Switching Node |
