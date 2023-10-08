#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

class UltrasonicSensor {
  public:
    UltrasonicSensor(int trigPin, int echoPin) : trigPin(trigPin), echoPin(echoPin) {
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
    }
    int get() {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      duration = pulseIn(echoPin, HIGH);
      distanceMM = duration * 0.343 / 2;
      if (distanceMM < 30 || distanceMM > 4110) {
        distanceMM = -1;
      }
      return static_cast<int>(distanceMM);
    }

  private:
    const int trigPin;
    const int echoPin;
    long duration;
    float distanceMM;
};
#endif
