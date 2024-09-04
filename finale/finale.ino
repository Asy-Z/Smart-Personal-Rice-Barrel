#define BLYNK_TEMPLATE_ID "TMPL6TVSLkuu7"
#define BLYNK_TEMPLATE_NAME "Smart Personal Rice Barrel"
#define BLYNK_AUTH_TOKEN "-tw3vRjceEol0vXL_EuLkfaxfrLtrLUY"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "HX711.h"

HX711 scale;

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
char auth[] = "-tw3vRjceEol0vXL_EuLkfaxfrLtrLUY";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "BlynkIOT";
char pass[] = "zaim2004";

float weight;
float calibration_factor = 4; // Adjust this value based on your calibration

void setup() {
  // Set up serial monitor
  Serial.begin(115200);
  Serial.println("HX711 calibration sketch");
  Serial.println("Remove all weight from the scale");
  Serial.println("After readings begin, place a known weight on the scale");
  Serial.println("Press + or a to increase calibration factor");
  Serial.println("Press - or z to decrease calibration factor");
  scale.begin(D2, D1); // Specify DOUT and CLK pins here (D2 for DOUT, D1 for CLK)
  scale.set_scale();
  scale.tare(); // Reset the scale to 0
  long zero_factor = scale.read_average(20); // Get a baseline reading
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  measureWeight();
}

void measureWeight() {
  scale.set_scale(calibration_factor); // Adjust to this calibration factor
  Serial.print("Reading: ");
  weight = scale.get_units(10); // Adjust the number of readings for stability
  if (weight < 0) {
    weight = 0.00;
  }
  Serial.print("Kilogram:");
  Serial.print(weight);
  Serial.print(" Kg");
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();
  Blynk.virtualWrite(V0, weight);
  Blynk.virtualWrite(V1, weight);

  // Log an event when the weight goes below a certain threshold
  if (weight < 1.0) { // You can adjust the threshold as needed
    Blynk.logEvent("rice_stock_is_depleting", "The rice barrel weight is below the threshold!");
    }

  // Delay before repeating measurement
  delay(100);
}
