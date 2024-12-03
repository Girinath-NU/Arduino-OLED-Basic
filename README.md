# Hello World on 0.9-inch OLED Display

This project demonstrates how to use a **0.9-inch OLED display** with an **Arduino** to display a simple "Hello World" message using the **Adafruit SSD1306** library.

## Components Required
- **Arduino Uno** (or compatible board)
- **0.9-inch OLED Display** (I2C interface)
- Jumper wires

## Wiring
The **0.9-inch OLED display** is connected to the Arduino using the **I2C protocol**. Here's how to wire it:

- **OLED VCC** → **5V** (or 3.3V depending on your OLED model)
- **OLED GND** → **GND**
- **OLED SDA** → **A4** (on Arduino Uno)
- **OLED SCL** → **A5** (on Arduino Uno)

### I2C Pinout on Arduino Uno:
- **A4**: SDA (Data)
- **A5**: SCL (Clock)

## Libraries Required
To use the OLED display, you'll need the following libraries:

1. **Adafruit GFX Library**  
   A core graphics library to support the **Adafruit SSD1306** display.

2. **Adafruit SSD1306 Library**  
   Library to interface with the SSD1306 OLED display.

You can install these libraries directly from the Arduino Library Manager:
- Open the Arduino IDE.
- Go to **Sketch** → **Include Library** → **Manage Libraries**.
- Search for **Adafruit GFX** and **Adafruit SSD1306**.
- Install both libraries.

## Code Overview

### 1. **Initialization**:
The code begins by including the necessary libraries for the display (`Adafruit_GFX.h` and `Adafruit_SSD1306.h`). It then defines the screen dimensions and I2C address (`0x3C` is the default for most OLED displays).

### 2. **Display Setup**:
In the `setup()` function, the OLED display is initialized using the `display.begin()` method, and the display buffer is cleared using `display.clearDisplay()`.

### 3. **Text Display**:
- The `display.setTextSize(1)` function sets the text size to 1, which is the smallest.
- The `display.setTextColor(SSD1306_WHITE)` sets the text color to white.
- The text is placed at the top-left corner using `display.setCursor(0, 0)`.
- The `display.println()` function is used to display the "Hello World" message on the screen.

### 4. **Sending Data to Display**:
Finally, the `display.display()` function sends the buffered data to the OLED, making the text visible on the screen.

### 5. **Loop**:
The `loop()` function is empty in this example because the display is static and does not change.

## Code:

```cpp
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define the screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// Define the I2C address (default is 0x3C)
#define OLED_ADDRESS 0x3C

// Create an instance of the display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

void setup() {
  // Start serial communication for debugging (optional)
  Serial.begin(9600);

  // Initialize the display
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println(F("SSD1306 initialization failed!"));
    for (;;); // Stop execution
  }

  // Clear the display buffer
  display.clearDisplay();

  // Display text
  display.setTextSize(1);              // Text size: 1 (smallest)
  display.setTextColor(SSD1306_WHITE); // White text
  display.setCursor(0, 0);             // Start at the top-left corner
  display.println(F("Hello World"));

  // Send buffer to display
  display.display();
}

void loop() {
  // Nothing in the loop for now
}
