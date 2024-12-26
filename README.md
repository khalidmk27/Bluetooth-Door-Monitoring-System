# Smart Bluetooth Door Lock System

## Overview
The Smart Bluetooth Door Lock System is an AVR microcontroller-based security solution designed to enhance door safety. This project leverages Bluetooth communication to control and monitor door security using a smartphone or other Bluetooth-enabled devices. The system also features an IR sensor and a buzzer for real-time door status monitoring and alerts.

## Features
- **Bluetooth Communication**: Control the system remotely using Bluetooth.
- **IR Sensor Integration**: Detects unauthorized access or door status.
- **Buzzer Alerts**: Provides an audible warning for security breaches.
- **Configurable Bluetooth Name**: Set a custom name for the Bluetooth device.
- **Simple and Efficient**: Operates with minimal hardware and low power consumption.

## Components
- Arduino Uno (ATmega328P microcontroller)
- Bluetooth module (e.g., HC-05)
- IR Sensor
- Buzzer
- Resistors and connecting wires

## Circuit Diagram
Connect the components as follows:
1. **Bluetooth Module**:
   - TXD to Arduino RX (Pin 0)
   - RXD to Arduino TX (Pin 1)
2. **IR Sensor**:
   - Output to Arduino Pin PB2
   - VCC and GND as per sensor specifications
3. **Buzzer**:
   - Positive terminal to Arduino Pin PB5
   - Negative terminal to GND

## Installation and Usage
### 1. Prerequisites
- AVR development tools (e.g., Atmel Studio or Arduino IDE)
- Basic knowledge of C programming and AVR microcontroller

### 2. Setting Up
1. Clone the repository:
   ```
   git clone https://github.com/yourusername/Smart-Bluetooth-Door-Lock-System.git
   ```
2. Open the project in your development environment.
3. Compile and upload the code to the Arduino Uno.

### 3. Operation
1. Power on the system.
2. Pair your smartphone or Bluetooth device with the system (default name: RSA).
3. Send the following commands via a Bluetooth terminal app:
   - `E`: Enable door monitoring.
   - `D`: Disable door monitoring.
4. When enabled, the buzzer will activate if the IR sensor detects unauthorized activity.

## Code Explanation
### Main Features:
- **UART Initialization**: Configures UART for Bluetooth communication.
- **Interrupt Handling**: Processes commands received via Bluetooth.
- **Door Monitoring**: Uses the IR sensor to check door status and activates the buzzer if necessary.

### Interrupt Service Routine (ISR):
Handles received Bluetooth data and sets flags for processing commands.

## Contributing
Contributions are welcome! Feel free to fork the repository, make enhancements, and submit pull requests.

## License
This project is licensed under the MIT License. See the LICENSE file for details.


