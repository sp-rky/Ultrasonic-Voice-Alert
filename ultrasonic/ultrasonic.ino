
#define TRIG A2
#define ECHO A1

void setup()
{
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(A0, LOW);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG, LOW);
  digitalWrite(TRIG, HIGH);
  delay(20);
  digitalWrite(TRIG, LOW);

  long pulse = pulseIn(ECHO, HIGH);
  Serial.print(pulse);
  if (pulse < 3000 && pulse > 10)
  {
    Serial.print(" !");
    digitalWrite(A0, HIGH);
    delay(100);
    digitalWrite(A0, LOW);
    delay(1000);
  }
  Serial.println();
  delay(50);
}
