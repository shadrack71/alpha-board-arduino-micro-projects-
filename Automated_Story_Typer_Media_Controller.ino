// Required libraries for keyboard and consumer (media) key emulation
#include <Keyboard.h>        // For standard keyboard functions (typing text, pressing keys like Enter, Win key)
#include "ConsumerKeyboard.h" // For media keys like volume up/down (ensure this library is installed)

// Pin Definitions for various components connected to the Arduino
// Analog pins are used for buttons here; digital pins could also be used.
int BUTTON1_PIN = A4;     // Pin for the first button (triggers part 1 of the story)
int BUTTON2_PIN = A5;     // Pin for the second button (triggers part 2 of the story)
int YELLOW_LED = 12;      // Pin for the yellow LED (used for visual feedback during typing)
int GREEN_LED = 11;       // Pin for the green LED (used for visual feedback at the end of sequences)
int RED_LED = 13;         // Pin for the red LED (used for visual feedback during sequences)
int BUZZER_PIN = 9;       // Pin for the piezo buzzer (for auditory feedback)
int POT1_PIN = A1;        // Pin for the potentiometer (controls system volume)

// Global variable to store the previous volume level read from the potentiometer
// This is used to detect changes in potentiometer position for volume control.
int prevVolume = 0;

/**
 * @brief Sends a consumer keyboard key press and release.
 *
 * This function is a helper to simplify sending media keys. It presses the
 * specified key and then immediately releases it.
 *
 * @param key The 16-bit key code for the consumer key (e.g., KEY_VOLUME_INCREMENT).
 */
void send_key(uint16_t key) {
  ConsumerKeyboard.press(key);   // Press the specified media key
  ConsumerKeyboard.release();  // Release the media key
}

/**
 * @brief Types a given string of text character by character.
 *
 * This function iterates through the input string and uses the Keyboard.write()
 * function to type each character. A small delay is added after each character
 * to simulate a more natural typing speed and ensure the host computer can keep up.
 *
 * @param text A null-terminated C-style string (const char*) to be typed.
 */
void typeSequence(const char* text) {
  for (int i = 0; text[i] != '\0'; i++) { // Loop until the null terminator of the string is reached
    Keyboard.write(text[i]);             // Type the current character
    delay(10);                           // Small delay to control typing speed
  }
}

/**
 * @brief Automates opening Notepad and typing the first part of a story.
 *
 * This function performs a sequence of keyboard actions to:
 * 1. Open the Windows "Run" dialog (Win + R).
 * 2. Type "notepad" and press Enter to launch Notepad.
 * 3. Type a predefined multi-line story ("Part 1: The Embedded Innovator").
 * It also uses LEDs and the buzzer for visual and auditory feedback during the process.
 */
void openNotepad() {
  digitalWrite(YELLOW_LED, HIGH);   // Turn on Yellow LED to indicate start of sequence

  // Open Run dialog (Windows Key + R)
  Keyboard.press(KEY_LEFT_GUI);     // Press the Left Windows Key
  Keyboard.press('r');              // Press the 'r' key
  Keyboard.releaseAll();            // Release all currently pressed keys
  delay(1000);                      // Wait for the Run dialog to appear

  digitalWrite(YELLOW_LED, LOW);    // Turn off Yellow LED

  // Type "notepad" into the Run dialog and press Enter
  typeSequence("notepad");
  Keyboard.press(KEY_RETURN);       // Press the Enter key
  Keyboard.releaseAll();            // Release all keys
  delay(800);                       // Wait for Notepad to open

  digitalWrite(YELLOW_LED, HIGH);   // Turn on Yellow LED, indicating typing has started

  // Type the first part of the story into Notepad
  typeSequence("=== Felix Biego: A Maker Journey ===\n");
  typeSequence("Part 1: The Embedded Innovator\n");
  digitalWrite(YELLOW_LED, LOW);    // Briefly turn off Yellow LED
  delay(500);
  typeSequence("Felix Biego is a software engineer hailing from Kenya  who has carved out a notable presence in the world of embedded systems and open-source development.\n");
  delay(200);
  typeSequence("With a passion for microcontrollers particularly the ESP32 and a knack for creating intuitive user interfaces, \n\n Felix has become a recognized name among hobbyists makers and developers in this space..\n");
  digitalWrite(YELLOW_LED, HIGH);   // Yellow LED on
  delay(200);
  typeSequence("His work often revolves around the Light and Versatile Graphics Library \n\n a popular choice for creating visually appealing and efficient UIs on resource-constrained devices.\n");
  digitalWrite(YELLOW_LED, LOW);    // Yellow LED off
  typeSequence("Felix's approach is deeply rooted in the open-source philosophy. \n He actively shares his projects and code, primarily through his GitHub profile (fbiego), \n\n allowing others to learn from, build upon, and contribute to his work. \n\nThis collaborative spirit is evident in the variety of repositories he maintains,\n\n ranging from libraries for ESP32 functionalities like managing RTC time\n");
  delay(150);
  digitalWrite(YELLOW_LED, HIGH);   // Yellow LED on
  typeSequence(" and Over-The-Air updates via Bluetooth Low Energy \n to more specific hardware interface libraries.\n His portfolio showcases a diverse skill set, encompassing C, C++, Kotlin, and Python, \n\n demonstrating  his versatility in both firmware development and accompanying application software.");
  delay(500);
  digitalWrite(YELLOW_LED, LOW);    // Yellow LED off
  typeSequence("\n");               // Add a newline at the end

  digitalWrite(RED_LED, HIGH);      // Turn on Red LED to signal end of typing part 1

  // Blink Yellow LED as a visual effect
  for(int i= 0; i < 7; i++) {
    digitalWrite(YELLOW_LED, HIGH);
    delay(100);
    digitalWrite(YELLOW_LED, LOW);
    delay(100);
  }

  digitalWrite(RED_LED, LOW);       // Turn off Red LED

  // Play a series of tones on the buzzer and blink Green LED
  for(int i=0; i<7; i++) {
    tone(BUZZER_PIN, 440, 150);   // Play a 440Hz (A4 note) tone for 150ms
    digitalWrite(GREEN_LED, HIGH);
    delay(100);
    digitalWrite(GREEN_LED, LOW);
    delay(100);                   // Ensure tone duration is respected before next iteration
  }
}

/**
 * @brief Automates opening Notepad and typing the second part of a story.
 *
 * Similar to `openNotepad()`, this function opens Notepad and types "Part 2"
 * of the story ("Part 2: Crafting Open-Source Solutions").
 * It also includes visual and auditory feedback.
 */
void openNotepad2() {
  digitalWrite(YELLOW_LED, HIGH);   // Yellow LED on: sequence start

  // Open Run dialog (Windows Key + R)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);                      // Wait for dialog

  digitalWrite(YELLOW_LED, LOW);    // Yellow LED off

  // Type "notepad" and execute
  typeSequence("notepad");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1500);                      // Wait longer for Notepad to launch reliably

  digitalWrite(YELLOW_LED, HIGH);   // Yellow LED on: typing starts

  // Type the second part of the story
  typeSequence("Part 2: Crafting Open-Source Solutions\n");
  delay(400);
  digitalWrite(YELLOW_LED, LOW);
  typeSequence("Among Felix Biego's standout contributions is his work on open-source smartwatch user interfaces. One such project,  \n highlighted by CircuitDigest, showcases a feature-rich UI for an ESP32 C3 Mini-based smartwatch with a 240x240 touch display.\n\n");
  delay(100);
  digitalWrite(YELLOW_LED, HIGH);
  typeSequence("This interface, built using LVGL on the Arduino framework,\n impressively packs features common in entry-level smartwatches,  \n including time display, weather information, notifications, settings, controls, QR code display, and even a racing game.\n");
  delay(100);
  digitalWrite(YELLOW_LED, LOW);
  typeSequence("This project serves as an excellent starting point and inspiration for those looking  \n to develop their own custom smartwatch firmware or other embedded GUI applications.\n");

  digitalWrite(RED_LED, HIGH);      // Red LED on

  // Flickering Yellow LED effect
  for(int i=0; i<5; i++) {
    digitalWrite(YELLOW_LED, HIGH);
    delay(100);
    digitalWrite(YELLOW_LED, LOW);
    delay(100);
  }
  digitalWrite(RED_LED, LOW);       // Red LED off

  Keyboard.write(KEY_BACKSPACE);    // Type a backspace (perhaps an intended effect or minor cleanup)

  // Play tones and blink Green LED
  for(int i=0; i<7; i++) {
    tone(BUZZER_PIN, 440, 150); // Play 440Hz tone for 150ms
    digitalWrite(GREEN_LED, HIGH);
    delay(100);
    digitalWrite(GREEN_LED, LOW);
    delay(100);
  }
}

/**
 * @brief Standard Arduino setup function. Runs once at startup.
 *
 * Initializes keyboard emulation, sets pin modes for buttons, LEDs, and the potentiometer.
 */
void setup() {
  Keyboard.begin();               // Initialize the standard keyboard library
  //ConsumerKeyboard.begin();       // Initialize the consumer keyboard library

  // Set pin modes for buttons as INPUT.
  // Consider using INPUT_PULLUP if buttons connect to GND when pressed
  // and no external pull-up resistors are used.
  pinMode(BUTTON1_PIN, INPUT);
  pinMode(BUTTON2_PIN, INPUT);

  // Set pin modes for LEDs as OUTPUT.
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Set pin mode for the potentiometer as INPUT.
  pinMode(POT1_PIN, INPUT);
  // Buzzer pin is implicitly OUTPUT when tone() is used, but explicit pinMode is good practice.
  pinMode(BUZZER_PIN, OUTPUT);
}

/**
 * @brief Standard Arduino loop function. Runs repeatedly after setup().
 *
 * Checks for button presses to trigger story typing functions.
 * Reads the potentiometer to control system volume.
 */
void loop() {
  // Check if Button 1 is pressed
  // Assumes button pulls pin HIGH when pressed. If it pulls LOW, change logic and use INPUT_PULLUP.
  if(digitalRead(BUTTON1_PIN)){ // If HIGH (true)
    openNotepad();              // Call function to type part 1 of the story
    delay(1000);                // Delay to prevent immediate re-triggering
  }

  // Check if Button 2 is pressed
  if(digitalRead(BUTTON2_PIN)){ // If HIGH (true)
    openNotepad2();             // Call function to type part 2 of the story
    delay(1000);                // Delay to prevent immediate re-triggering
  }

  // --- System Volume Control via Potentiometer ---
  int pot1_raw_value = analogRead(POT1_PIN); // Read the raw analog value from potentiometer (0-1023)

  // Map the raw potentiometer value (0-1023) to a 0-100 range for volume representation
  int volume = map(pot1_raw_value, 0, 1023, 0, 100);

  // Check if the mapped volume has changed compared to the previous reading
  if (volume > prevVolume) {
    // Volume increased: send volume up commands
    // Sends multiple commands to make the volume change more noticeable per pot movement.
    for(int i = 0; i < 5; i++){ // Send 5 volume up ticks
      send_key(KEY_VOLUME_INCREMENT); // Use helper function to send media volume up key
    }
  }
  else if (volume < prevVolume) {
    // Volume decreased: send volume down commands
    for(int i = 0; i < 5; i++){ // Send 5 volume down ticks
      send_key(KEY_VOLUME_DECREMENT); // Use helper function to send media volume down key
    }
  }

  prevVolume = volume; // Update prevVolume with the current volume for the next loop iteration
  delay(50);           // Short delay for stability and to prevent overly rapid volume changes
}
