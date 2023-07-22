# Digital-Thermostat-System
The design and implementation of a digital thermostat system.

Digital Thermostat Implementation using Arduino

This Arduino project implements a digital thermostat system with a user interface and temperature control logic. The system allows the user to set the desired temperature and observes the current temperature readings on a 16x2 LCD display. The thermostat maintains the room temperature as close to the desired temperature as possible by activating heating or cooling systems.

Hardware Requirements:

Arduino board (e.g., Arduino Uno)
16x2 LCD display with the following connections:
RS pin: 12
EN pin: 11
D4 pin: 5
D5 pin: 4
D6 pin: 3
D7 pin: 2
Two push buttons for user interaction, connected to analog pins A0 and A1
Jumper wires
Operation:

Upload the code to the Arduino board using the Arduino IDE.
Connect the LCD display and push buttons to the Arduino board as specified in the code.
The LCD will display "Desired Temperature: 25" on the first line and "Current Temperature: 25" on the second line, indicating the initial desired and current temperatures, respectively.
Use the push buttons to adjust the desired temperature. Pressing the up button (connected to A0) will increase the desired temperature, and pressing the down button (connected to A1) will decrease the desired temperature. The temperature range is between 0°C and 100°C.
The control logic will activate the heating system when the current temperature falls below the desired temperature minus the "heatingThreshold" (default 2 degrees Celsius). Similarly, the cooling system will activate when the current temperature rises above the desired temperature plus the "coolingThreshold" (default 2 degrees Celsius).
The system will update the LCD display with the new desired and current temperatures after each adjustment and temperature simulation.
The temperature simulation is a basic random fluctuation within ±2 degrees Celsius (you can replace this with actual sensor readings in a real-world scenario).
Note:
This is a simulated implementation, and the actual behavior may vary depending on the real hardware and sensor used.








