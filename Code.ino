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
