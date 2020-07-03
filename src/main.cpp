#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial ESP_BT;

#define LED_R 15
#define LED_G 4
#define LED_Y 5
#define LED_B 2
#define POT   33

void setup()
{
    Serial.begin(9600);
    ESP_BT.begin("ESP32_BT_IOT");
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_Y, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(POT, INPUT);
}

void loop()
{
    if (ESP_BT.available())
    {
        int incoming = ESP_BT.read();
        int potValue;

        Serial.print("Received: ");
        Serial.println((char) incoming);

        switch (incoming)
        {
            case 'R':
                digitalWrite(LED_R, !digitalRead(LED_R));
                break;
            case 'Y':
                digitalWrite(LED_Y, !digitalRead(LED_Y));
                break;
            case 'G':
                digitalWrite(LED_G, !digitalRead(LED_G));
                break;
            case 'B':
                digitalWrite(LED_B, !digitalRead(LED_B));
                break;
            case 'P':
                potValue = analogRead(POT);

                Serial.print("POT: ");
                Serial.println(potValue);

                ESP_BT.println(potValue);
                break;
            default:
                break;
        }
    }
}
