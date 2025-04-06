/*
  @file UltrasonicSensor_HC-SR04.ino
  @brief HC-SR04 Ultrasonic Sensor with the ARIES v2 Board
  @detail Measures the distance of a target object and display it on serial monitor
  
   Reference aries board: https://vegaprocessors.in/blog/ultrasonic-sensor-with-thejas-soc/
   
   *** Ultrasonic Sensor(HC-SR04) ***
   Connections:
   HC-SR04    Aries Board
   VCC      -   5V
   GND      -   GND
   Echo     -   GPIO1
   Trig     -   GPIO0
*/

#define echoPin 1 // attach pin GPIO-1 Aries to pin Echo of HC-SR04
#define trigPin 0 //attach pin GPIO-0 Aries to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(115200);  // Serial Communication is starting with 115200 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Aries V2.0");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);
}
