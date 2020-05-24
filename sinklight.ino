// defines pins numbers
const int trigPin = 3;
const int echoPin = 4;

// define relay pin number
const int relayPin = 5;

// defines variables
long duration;
int distance;

bool is_present = false; // Is a human present?

int presence_distance = 200; // How far away a human has to be to trigger the servo.


void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(relayPin, OUTPUT);

  pinMode(13, OUTPUT); // Use the onboard light to indicate when a human is detected.
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
    digitalWrite(relayPin, HIGH);
  } else if (distance >= presence_distance && is_present == true) {
    is_present = false;
    digitalWrite(relayPin, LOW);
  }
  delay(2000);
}
