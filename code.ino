#include "CTBot.h"

CTBot myBot;

String ssid = "Veendy-Suseno";  //nama ssid wifi kalian
String pass = "Admin12345";     //password wifi kalian
String token = "XXXX";          //token bot baru kalian
const int id = XXXX;            //id telegram kalian

int buzzer = D1;
int tomb = D0;

void setup() {
    Serial.begin(9600);
    Serial.println("Starting TelegramBot...");
    myBot.wifiConnect(ssid, pass);
    myBot.setTelegramToken(token);
    if (myBot.testConnection()) {
        Serial.println("Koneksi Bagus");
    } else {
        Serial.println("Koneksi Jelek");
    }
    pinMode(buzzer, OUTPUT);
    pinMode(tomb, INPUT_PULLUP);
}

void loop() {
    int push = digitalRead(tomb);
    if (push == LOW)  {
        tone(buzzer, 1000, 200);
        myBot.sendMessage(id, "Bel Berbunyi");
    }
    else {
        noTone(buzzer);
    }
    delay(100);
}