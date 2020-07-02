#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial ESP_BT;

#define LED_R 15
#define LED_G 4
#define LED_Y 5
#define LED_B 2

void setup()
{
    Serial.begin(9600);
    ESP_BT.begin("ESP32_BT_IOT");
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_Y, OUTPUT);
    pinMode(LED_B, OUTPUT);
}

void loop()
{
    if (ESP_BT.available())
    {
        int incoming = ESP_BT.read();
        Serial.print("Received: ");
        Serial.println(incoming);

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
            default:
                break;
        }
    }
}
