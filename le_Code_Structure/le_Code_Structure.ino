void setup() {
  Serial.begin(115200);
  setupLoadCell(); 
  setupBlynk(); 
}

void loop() {
  Blynk.run(); /
  
  double load = scale.get_units();

  Blynk.virtualWrite(V1, load);

  if (load < 1.0) {
    Blynk.notify("Rice load is low!");
  }
}

