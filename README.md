# ATmega32U4 Onboard Components Project Collection

[![Arduino CI](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME/actions/workflows/arduino-ci.yml/badge.svg)](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME/actions/workflows/arduino-ci.yml) <!-- Optional: Add a CI badge if you set one up -->
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT) <!-- Optional: Choose a license -->

A collection of Arduino sketches designed for a custom or development board based on the Atmel ATmega32U4 microcontroller (compatible with Arduino Micro/Leonardo bootloader). This board features a rich set of built-in components, allowing for diverse and engaging projects without external hardware.

## Board Features Utilized

This project leverages the following onboard components:

* **Microcontroller:** ATmega32U4 (e.g., Arduino Micro/Leonardo compatible)
* **USB:** USB Type-C connector
* **LEDs:** 3x (Red, Yellow, Green)
* **Buttons:** 2x Push Buttons
* **Potentiometers:** 2x Analog Potentiometers
* **Audible Output:** 1x Piezo Buzzer
* **Light Sensor:** 1x Light Dependent Resistor (LDR)
* **Temperature Sensor:** 1x NTC Thermistor
* **Infrared:** 1x IR Transmitter LED & 1x IR Receiver Sensor

## Projects Included

This repository contains various example projects, ranging from beginner to advanced levels:

1.  **LED & Button Fun:** Control LEDs with button presses and combinations.
2.  **Potentiometer Control:** Adjust LED brightness and buzzer tone frequency using potentiometers.
3.  **Simple Light Meter:** Indicate ambient light levels (Dark, Dim, Bright) using LEDs based on LDR readings.
4.  **Basic Temperature Alert:** Monitor temperature with the NTC and trigger an LED/buzzer alarm.
5.  **"Follow Me" Light Game:** A simple Simon-like memory game using LEDs, buttons, and a potentiometer.
6.  **IR Proximity Detector:** Detect nearby objects using the IR transmitter and receiver.
7.  **USB Keyboard Typer:** Use the ATmega32U4's HID capabilities to type characters selected by a potentiometer.
8.  **NTC & LDR Data Logger (USB Keyboard):** Periodically "type out" sensor data to a connected computer.
9.  **Simple IR Remote Control:** Basic IR signal transmission and reception to control LEDs.
10. **Mini MIDI Controller:** Turn the board into a USB-MIDI device controlling notes and CC messages with potentiometers and buttons.
    * *(Add more projects as you develop them)*

Each project is located in its own folder within the `examples/` or `sketches/` directory (e.g., `Project_01_LED_Button_Fun/Project_01_LED_Button_Fun.ino`).

## Hardware Setup & Pinout

The sketches assume the following pin connections for the onboard components. Please verify and adjust if your board has a different layout:

* Red LED: Pin `2`
* Yellow LED: Pin `3`
* Green LED: Pin `4`
* Button 1: Pin `5` (configured with `INPUT_PULLUP`)
* Button 2: Pin `6` (configured with `INPUT_PULLUP`)
* Potentiometer 1: Pin `A0`
* Potentiometer 2: Pin `A1`
* Buzzer: Pin `7` (PWM capable)
* LDR: Pin `A2` (connected in a voltage divider)
* NTC Thermistor: Pin `A3` (connected in a voltage divider)
* IR Transmitter LED: Pin `8`
* IR Receiver Sensor: Pin `9`

**Note on PWM Pins:** For projects requiring `analogWrite()` (like LED brightness control), ensure the LED is connected to a PWM-capable pin. On Arduino Micro/Leonardo, PWM pins are typically 3, 5, 6, 9, 10, 11, 13. Adjust sketches accordingly if needed (e.g., Project 2 uses Pin 3 for PWM Red LED control).

## Software Requirements

* **Arduino IDE:** Version 1.8.x or later (or PlatformIO).
* **Board Selection:** In Arduino IDE, select "Arduino Leonardo" or "Arduino Micro" (or the appropriate board definition for your ATmega32U4 board).
* **Libraries:**
    * `Keyboard.h`: For USB Keyboard projects (comes standard with Arduino IDE for Leonardo/Micro).
    * `MIDIUSB.h`: For the USB MIDI Controller project. Installable via the Arduino Library Manager.
    * *(List any other specific libraries if used)*

## Getting Started

1.  **Clone the Repository:**
    ```bash
    git clone [https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git)
    cd YOUR_REPOSITORY_NAME
    ```
2.  **Open a Sketch:** Navigate to the desired project folder and open the `.ino` file in the Arduino IDE.
3.  **Select Board & Port:** Ensure "Arduino Leonardo" or "Arduino Micro" (or your specific board) and the correct COM port are selected in the IDE.
4.  **Install Libraries:** If a project requires a specific library (like `MIDIUSB.h`), install it using the Arduino Library Manager (`Sketch > Include Library > Manage Libraries...`).
5.  **Upload:** Click the "Upload" button.

## How to Use Specific Projects

*(Optional: Add brief instructions or notes for more complex projects here)*

* **USB HID Projects (Keyboard/MIDI):** Be aware that when these sketches are running, your board will act as a USB Keyboard or MIDI device to your computer. To stop this behavior, upload a different sketch (e.g., the basic `Blink` sketch or one of the non-HID projects from this repository).
* **Sensor Calibration:** The LDR and NTC thermistor projects use raw analog values or simple mapping. For accurate light level or temperature readings, you may need to calibrate the thresholds or implement conversion formulas (e.g., Steinhart-Hart for the NTC) based on your specific components and their voltage divider circuits.

## Contributing

Contributions are welcome! If you have improvements, bug fixes, or new projects for this board:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/YourAmazingFeature`).
3.  Commit your changes (`git commit -m 'Add some YourAmazingFeature'`).
4.  Push to the branch (`git push origin feature/YourAmazingFeature`).
5.  Open a Pull Request.

Please ensure your code is well-commented and follows the general style of the existing projects.

## Future Ideas / To-Do

*(Optional: List any planned features or projects)*

* Implement more advanced sound synthesis with the buzzer.
* Develop a project using the `Mouse.h` library.
* Create a combined sensor station that logs data to an SD card (if an SD module were added).
* Refine IR communication with proper modulation/demodulation (might require external components or advanced timer usage).

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details. (Or choose another license like Apache 2.0, GPL, etc.)

---

*Remember to replace `YOUR_USERNAME` and `YOUR_REPOSITORY_NAME` with your actual GitHub username and repository name.*
*If you choose to include a license, create a `LICENSE.md` file in your repository with the text of the chosen license (e.g., MIT License is very common and permissive).*
