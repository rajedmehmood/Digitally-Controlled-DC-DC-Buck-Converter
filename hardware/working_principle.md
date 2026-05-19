# Working Principle

The buck converter reduces DC voltage using PWM switching.

The ESP32 generates PWM signals.

The TC4420 amplifies PWM gate drive.

The MOSFET switches rapidly at 25kHz.

The inductor stores and releases energy.

The capacitor smooths the output waveform.

Output voltage is controlled by duty cycle.

Vout = D × Vin
