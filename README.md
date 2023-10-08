# UltrasonicSensor
Simple library to get distance in mm using HC-SR04 ultrasonic sensor with ESP32 in Arduino enviroment-

NOTE: Return -1 when out of range

Example:
```c++
UltrasonicSensor us(21, 12);
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Distance (mm): ");
  Serial.println(us.get());
  delay(1000);
}
```
