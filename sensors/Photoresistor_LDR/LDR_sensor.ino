#define ledPin 13
#define ldrPin A0

void setup() {

  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {

  int ldrStatus = analogRead(ldrPin);
  
  if (ldrStatus <= 200) {

    digitalWrite(ledPin, HIGH);
    Serial.print("Its DARK, Turn on the LED : ");
    Serial.println(ldrStatus);

  } else {

    digitalWrite(ledPin, LOW);
    Serial.print("Its BRIGHT, Turn off the LED : ");
    Serial.println(ldrStatus);

  }

}