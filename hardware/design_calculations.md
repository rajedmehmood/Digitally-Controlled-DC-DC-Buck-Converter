# Design Calculations

## Buck Converter Theory

In ideal continuous-conduction mode, the output voltage $V_{\text{out}}$ follows the duty cycle $D$ of the PWM: 

$$V_{\text{out}} = D \times V_{\text{in}}$$

Where $V_{\text{in}} = 12\text{ V}$. For example, a 50% duty yields $\sim 6\text{ V}$.

**Duty cycle range:** We adjust $D$ from 0 to $\sim 0.8$ (80%) safely. At 100% duty the MOSFET is fully ON ($V_{\text{out}} \approx V_{\text{in}}$). Over $\sim 80\%$ there is little regulation headroom; we limit to 90% in code to allow headroom.

## Inductor Selection

* Desired inductance: $L = 150\ \mu\text{H}$ (toroidal, 5 A rated).  
* Estimate ripple current $\Delta I_L$: 

$$\Delta I_L \approx \frac{(V_{\text{in}} - V_{\text{out}}) \times D}{L \times f_{\text{sw}}}$$

* Example at 50% duty (6 V output): 

$$\Delta I_L \approx \frac{(12 - 6) \times 0.5}{150 \times 10^{-6} \times 25 \times 10^3} \approx 0.8\text{ A}$$

* This is a large ripple; in practice the chosen $150\ \mu\text{H}$ is moderate, trading size vs. ripple. If more output current was needed, a higher-$L$ inductor or higher switch frequency would be used.

## Capacitor Selection

* Output voltage ripple $\Delta V_{\text{out}}$ is roughly $\frac{\Delta I_L}{8 f_{\text{sw}} C}$ (assuming triangular ripple). 
* With $C = 220\ \mu\text{F}$, $\Delta I_L \approx 0.8\text{ A}$, and $f_{\text{sw}} = 25\text{ kHz}$: 

$$\Delta V_{\text{out}} \approx \frac{0.8}{8 \times 25 \times 10^3 \times 220 \times 10^{-6}} \approx 0.18\text{ V (peak-to-peak)}$$

* We use $220\ \mu\text{F}$ (low-ESR electrolytic) to keep ripple < 200 mV; two in parallel ($440\ \mu\text{F}$ total) can be used for even lower ripple.

## Current and Power

* **Output current:** $I_{\text{out}} = \frac{V_{\text{out}}}{R_{\text{load}}}$
  * *Example:* At $V_{\text{out}} = 6\text{ V}$ with $10\ \Omega$ load, $I_{\text{out}} = 0.6\text{ A}$.  
* **Output power:** $P_{\text{out}} = V_{\text{out}} I_{\text{out}}$  
* **Input power:** $P_{\text{in}} = V_{\text{in}} I_{\text{in}} \approx V_{\text{in}} I_{\text{out}}$ (neglecting small switch current).  
* **Efficiency:** $\eta = \frac{P_{\text{out}}}{P_{\text{in}}} \times 100\%$
  * Buck converters typically achieve $>90\%$ under moderate load. With 0.6 A load and our hardware, measured $\eta \approx 70\%$ due to conduction and switching losses.

## MOSFET & Diode Selection

### MOSFET
Choose logic-level $V_{GS(\text{th})}$ so that a 12 V gate (from TC4420) fully turns it on. A $60\text{--}80\text{ V}$ $V_{DS}$ rating is common for 12 V in; $R_{DS(\text{on})}$ should be very low to reduce loss. Example parts:  
* **IRLZ44N:** $60\text{ V}$, $47\text{ A}$, $R_{DS(\text{on})} \approx 0.022\ \Omega$ at $V_{GS} = 10\text{ V}$.  
* **IRF3205PbF:** $55\text{ V}$, $110\text{ A}$, $R_{DS(\text{on})} \approx 0.008\ \Omega$ at $V_{GS} = 10\text{ V}$.  

### Schottky Diode
Must handle $1.5\text{ A}+$ and withstand 12 V. A fast rectifier (SR1645 or similar) is used to minimize forward drop ($\sim 0.4\text{--}0.6\text{ V}$).

## Overcurrent Protection

Current limit is set at $\sim 1.2\text{ A}$. The INA219 measures current; if $I_{\text{out}} > 1.2\text{ A}$, firmware disables PWM. This prevents overload on the MOSFET and power supply. Use a similar approach or a polyfuse for hardware protection.

## Summary of Key Values


| Parameter | Value |
| :--- | ---: |
| Input voltage ($V_{\text{in}}$) | 12 V |
| PWM Frequency ($f_{\text{sw}}$) | 25 kHz |
| Duty cycle range ($D$) | 0–90% |
| Inductor ($L$) | $150\ \mu\text{H}$, 5 A |
| Output capacitance ($C$) | $220\ \mu\text{F}$ ($\times 1\text{--}2$) |
| Max output current | $\sim 1.2\text{ A}$ ($10\ \Omega$ load) |
| Output ripple (est.) | $\sim 0.15\text{ V}_{\text{pp}}$ @ 50% duty |
