#include "HX711.h"

HX711 scale;

// Define your calibration factor. You need to determine this value through calibration.
// This factor converts the raw readings to grams. You may need to adjust it as per your setup.
const float calibrationFactor = 2050.0; // Replace with your actual calibration factor

void setup() {
  Serial.begin(115200);
  scale.begin(D2, D1); // Initialize the HX711 with D2 as the data pin and D1 as the clock pin
  scale.set_scale(calibrationFactor); // Set the calibration factor
  scale.tare(); // Reset the scale to zero (remove any initial load).
  Serial.println("Ready to measure...");
}

void loop() {
  if (scale.is_ready()) {
    float weight = scale.get_units(10); // Read the weight data and average over 10 readings
    Serial.print("Weight: ");
    Serial.print(weight);
    Serial.println(" grams");
  }
  delay(1000); // Adjust the reading interval as needed
}



