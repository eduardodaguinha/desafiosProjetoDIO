void setup()
{
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  if (analogRead(A0) > 300) {
    digitalWrite(11, HIGH);
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(11, LOW);
    digitalWrite(4, LOW);
    delay(1000);
  } else {
    digitalWrite(11, LOW);
    digitalWrite(4, LOW);
  }
}