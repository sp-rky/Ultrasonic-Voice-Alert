int trig = 2;
int echo = 3;

int redLED = 11;
int yellowLED = 10;
int greenLED = 9;

int mutedLED = 13;

int muteSwitch = 5;

int play = 7;

// loop variable (ignore)
int distance;
bool notPressedLastLoop = true;
bool muted = false;

void setup() {
  // initialise ultrasonic outputs (arduino pins default to inputs)
  pinMode(trig, OUTPUT);

  // initialise LED outputs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(mutedLED, OUTPUT);

  // initialise playback output
  pinMode(play, OUTPUT);

  // begin transmitting over serial
  Serial.begin(38400);
}

void loop() {
  // get the distance as read by the ultrasonic sensor (in centimeters)
  distance = readUltrasonicDistance(trig, echo);

  // check to see if the mute switch is being pressed
  if(digitalRead(muteSwitch) == HIGH && notPressedLastLoop) {
    muted = !muted;
    notPressedLastLoop = false;
  } 
  else if(digitalRead(muteSwitch) == HIGH && !notPressedLastLoop) {
    notPressedLastLoop = false;
  }
  else if(digitalRead(muteSwitch) == LOW) {
    notPressedLastLoop = true;
  }

  // set the mute indicator LED to light if it is muted
  if(muted) {
    digitalWrite(mutedLED, HIGH);
  }
  else {
    digitalWrite(mutedLED, LOW);
  }

  // colour the LEDs accordingly
  switch(distance) {
    case 0 ... 25:
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);
      break;
    case 26 ... 50:
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);
      break;
    case 51 ... 1000:
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);
      break;
    default:
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);
      break;
  }

  // signal the sound player to play a sound if the distance is below 25, as long as it isn't muted
  if(distance < 25 && !muted) {
    digitalWrite(play, HIGH);
    delay(5);
    digitalWrite(play, LOW);
  }

  // output the distance to the serial console
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
}

int readUltrasonicDistance(int triggerPin, int echoPin) {
  // send out an ultrasonic ping from the sensor
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  // read how long it takes for the sound to return
  int duration = pulseIn(echoPin, HIGH);

  // convert the duration into a distance (cm)
  return duration / 29 / 2;
}
