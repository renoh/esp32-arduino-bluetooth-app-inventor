#include <Arduino.h>

#define LED_R 15
#define LED_G 4
#define LED_Y 5
#define LED_B 2

void setup()
{
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_Y, OUTPUT);
    pinMode(LED_B, OUTPUT);
}

void loop()
{
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_B, LOW);
    delay(500);
    digitalWrite(LED_Y, HIGH);
    digitalWrite(LED_R, LOW);
    delay(500);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_Y, LOW);
    delay(500);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_G, LOW);
    delay(500);
}
