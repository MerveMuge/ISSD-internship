#define TEMPERATURE_PIN 1

#define LDR_LED_PIN 13
#define LDR_INPUT_PIN A0

#define RELAY_PIN 4

class Temperature {
  public:
    virtual void temperature() {
      int val = analogRead(TEMPERATURE_PIN);
      float mv = ( val / 1024.0) * 5000;
      float cel = mv / 10;
      float farh = (cel * 9) / 5 + 32;

      Serial.print("TEMPRATURE = ");
      Serial.print(cel);
      Serial.print("*C");
      Serial.println();
      delay(1000);
    }

};
Temperature * temperature_obj;

class Relay {
  public:
    virtual void relay() {
      digitalWrite(RELAY_PIN, HIGH);// turn relay ON
      Serial.println("Relay ON");
      delay(300);// wait for 5 seconds

      digitalWrite(RELAY_PIN, LOW);// turn relay OFF
      Serial.println("Relay OFF");
      delay(1000);// wait for 3 secons

    }

};
Relay * relay_obj;

class Photoresistor {
  public:
    virtual void photoresistor_LDR() {
      int ldrStatus = analogRead(LDR_INPUT_PIN);

      if (ldrStatus <= 200) {

        digitalWrite(LDR_LED_PIN, HIGH);
        Serial.print("Its DARK, Turn on the LED : ");
        Serial.println(ldrStatus);

      } else if (ldrStatus > 500) {

        digitalWrite(LDR_LED_PIN, LOW);
        Serial.print("Its BRIGHT, Turn off the LED : ");
        Serial.println(ldrStatus);

      }
    }

};
Photoresistor * ldr_obj;

void setup()
{
  Serial.begin(115200);

  pinMode(LDR_LED_PIN, OUTPUT);
  pinMode(LDR_INPUT_PIN, INPUT);

  pinMode(RELAY_PIN , OUTPUT);

  temperature_obj = new Temperature();
  relay_obj = new Relay();
  ldr_obj = new Photoresistor();
}


void loop()
{
  temperature_obj->temperature();
  relay_obj->relay();
  ldr_obj->photoresistor_LDR();
}
