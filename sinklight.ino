#include <Servo.h> 

int servoPin = 2; // Pin to communicate with the servo

Servo servo;

int servoAngle = 0;   // servo position in degrees

// defines pins numbers
const int trigPin = 3;
const int echoPin = 4;

// defines variables
long duration;
int distance;

bool is_present = false; // Is a human present?

int presence_distance = 100; // How far away a human has to be to trigger the servo.


void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(13, OUTPUT);
}


void loop()
{  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  
  if (distance < presence_distance && is_present == false) {
    is_present = true;
    digitalWrite(13, HIGH);
    servo.write(80); //on
    delay(500);
    servo.write(50);
    delay(2000);
  } else if (distance >= presence_distance && is_present == true) {
    is_present = false;
    digitalWrite(13, LOW);
    servo.write(25); //off
    delay(500);
    servo.write(50);
    delay(2000);
  }
  delay(500);
}
