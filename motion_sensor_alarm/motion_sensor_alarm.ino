// Define Pins

// uno
int tonePin = 7;
int redLight = 8;
int trigPin = 9;
int echoPin = 10;
// nano
//int tonePin = 0;
//int redLight = 10;
//int trigPin = 11;
//int echoPin = 12;
int distance;
int safeDistance;

boolean isOn = false;
long duration;

void setup() {
  pinMode(trigPin, OUTPUT); // sets the trigPin as an output
  pinMode(echoPin, INPUT); // sets the echoPin to an input
  pinMode(redLight, OUTPUT);

  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // clears the drigPin
  digitalWrite(trigPin,LOW);
  
  delay(2);

  // sets the trigPin on HIGH state for 10 microsecods
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  //distance = duration/29/2;
  distance = (duration*.0343)/2; 
  if (duration==0) {
    Serial.println("Warning: no pulse from sensor");
    digitalWrite(redLight, false);
  } 
  else {
    Serial.print("distance to nearest object:");
    Serial.println(distance);
    Serial.println(" cm");
    if (distance <= 10) {
      digitalWrite(redLight, true);
      tone(tonePin, 700, 800);
    } else {
      digitalWrite(redLight, false);
      noTone(tonePin);
      
    }
  }
  delay(100);
}






