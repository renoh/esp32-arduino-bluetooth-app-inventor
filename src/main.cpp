#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial ESP_BT;

#define LED_R 15
#define LED_G 4
#define LED_Y 5
#define LED_B 2
#define POT   33

int key = 0;

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
        char variableKey[3 + 1] = {};
        int fixedKey = 150;
        int i = 0;
        int read = 1;
        int incoming = ESP_BT.peek();
        int potValue;

        Serial.print("ReceivedOrig: ");
        Serial.println((char)incoming);

        incoming ^= key;
        Serial.print("ReceivedConv: ");
        Serial.println((char)incoming);

        switch (incoming)
        {
            case 'K':
                read = 0;
                incoming = ESP_BT.read();
                Serial.print("Received2: ");
                Serial.println((char) incoming);
                do {
                    if (ESP_BT.available()) {
                        incoming = ESP_BT.read();
                        Serial.print("ReceivedK: ");
                        Serial.println((char) incoming);
                        if ((char)incoming == '.' || incoming < '0' || incoming > '9') {
                            break;
                        } else {
                            variableKey[i] = (char) incoming;
                            i++;
                        }
                    }
                } while (1);
                key = fixedKey ^ atoi(variableKey);
                break;
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
                if (key != 0)
                {
                    read = 0;
                    key = 0;
                }
                break;
        }

        if (read) ESP_BT.read();
    }
}
