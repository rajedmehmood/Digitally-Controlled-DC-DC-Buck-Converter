# Circuit Connections

## ESP32 → TC4420

| ESP32 | TC4420 |
|--------|---------|
| GPIO25 | INPUT |
| GND | GND |

## TC4420

| Pin | Connection |
|-----|-------------|
| VDD | 12V |
| GND | Common Ground |
| OUT | MOSFET Gate |

## MOSFET

| Pin | Connection |
|------|-------------|
| Gate | TC4420 Output |
| Source | GND |
| Drain | Switching Node |

## Diode

| Side | Connection |
|------|-------------|
| Cathode | Switching Node |
| Anode | GND |

## INA219

| INA219 | ESP32 |
|--------|------|
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO21 |
| SCL | GPIO22 |

## Inductor

Switching Node → Inductor → Output

## Capacitor

Output → Capacitor → GND
