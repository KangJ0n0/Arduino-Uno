#include <SPI.h>
#include <MFRC522.h>
#include <CTBot.h>
#include <Wire.h>  // Include the Wire library for I2C
#include <LiquidCrystal_I2C.h>  // Include the LiquidCrystal_I2C library

#define RST_PIN         25          // Pin RST pada RFID
#define SS_PIN          5          // SDA/SS Pin pada RFID
#define BUZZER_PIN       4          // Pin yang digunakan untuk mengontrol buzzer
#define RED_PIN         13          // Pin yang digunakan untuk mengontrol led merah
#define GREEN_PIN       27          // Pin yang digunakan untuk mengontrol led hijau
#define pin_relay       15

MFRC522 mfrc522(SS_PIN, RST_PIN); 
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27, 16 columns, 2 rows

CTBot myBot;

const char* ssid = "awok"; //Nama WiFi yang akan terhubung dengan ESP32
const char* password = "123456789"; //Password WiFi
const char* token = "xxxxxxxx"; //Token Bot Telegram

// Struktur data untuk menyimpan ID dengan nama
struct User {
    const char* uid;
    const char* name;
};

// Array untuk menyimpan ID dengan nama
User users[] = {
    {"330EC70C", "Joko"},
    {"D3AEDC24", "Risma"},
    {"E3F7E334", "Sir Andi"},
};

void setup() {
    Serial.begin(9600);         // Inialiasasi komuninasi dengan serial monitor
    while (!Serial);            
    SPI.begin();                // Init SPI bus
    mfrc522.PCD_Init();         // Init MFRC522
    delay(4);                   // Delay
    mfrc522.PCD_DumpVersionToSerial();    //Tampilkan secara detail Pembaca Kartu MFRC522
    Serial.println(F("Memindai PICC untuk melihat UID..."));
    myBot.wifiConnect(ssid, password);
    myBot.setTelegramToken(token);

    if (myBot.testConnection())
      Serial.println("\nTerhubung ke WiFi");
    else
      Serial.println("\nTidak dapat terhubung");

    pinMode(BUZZER_PIN, OUTPUT);  // Set pin buzzer sebagai output
    pinMode(RED_PIN, OUTPUT);     // Set pin led merah sebagai output
    pinMode(GREEN_PIN, OUTPUT);   // Set pin led hijau sebagai output
    pinMode(pin_relay, OUTPUT);

    // Initialize the LCD
    lcd.init();
    Wire.begin(12,14);
    lcd.backlight();
}

//function untuk mengirimkan notifkasi ke bot telegram dengan meneyertakan ID Chat
void sendTelegramNotification(String notification) {
  String message = notification;
  if (myBot.sendMessage(-1001848147121, message)) {
    Serial.println("Notikasi Terkirim");
  } else {
    Serial.println("Notifikasi gagal terkirim");
  }
}

void loop() {
   digitalWrite(pin_relay, HIGH);
   lcd.clear();  // Clear the LCD
   lcd.setCursor(0, 0);  // Set cursor to the first column and first row

    //  lcd.setCursor(0,0);
   lcd.print("Tempelkan Kartu!");
    // Array untuk menyimpan UID dalam format string
    char uidString[16]; // Panjang 16 sesuai dengan panjang maksimum UID (8 byte) dalam format hexadecimal

    // Reset loop jika tidak ada kartu baru pada sensor/pembaca. Ini menyimpan seluruh proses saat idle.
    if (!mfrc522.PICC_IsNewCardPresent()) {
        return;
    }

    // Pilih salah satu kartu
    if (!mfrc522.PICC_ReadCardSerial()) {
        return;
    }

    // Mengkonversi UID ke dalam bentuk string
    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; ++i) {
        if (mfrc522.uid.uidByte[i] < 0x10) {
            uid += "0";
        }
        uid += String(mfrc522.uid.uidByte[i], HEX);
    }
    
    // Koversi UID ke Kapital
    uid.toUpperCase();

    // Konversi UID to char array
    uid.toCharArray(uidString, 16); // Mengonversi UID ke huruf kapital

    // Tampilkan UID
    Serial.print(F("UID Value: "));
    Serial.println(uidString);

    mfrc522.PICC_HaltA();
    // Hentikan enkripsi pada PCD
    mfrc522.PCD_StopCrypto1();

    // Periksa apakah UID cocok dengan keyID
    bool accessGranted = false;
    const char* userName = "";
    for (size_t i = 0; i < sizeof(users) / sizeof(users[0]); i++) {
        if (strcmp(uidString, users[i].uid) == 0) {
            Serial.println(F("Akses Diberikan"));
            accessGranted = true;
            userName = users[i].name;
            break;
        }
    }

    if (accessGranted) {
        lcd.clear();
        lcd.print("Akses Diterima");  // Display "Akses Diterima" on LCD
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(pin_relay, LOW);
        delay(3000);
        digitalWrite(pin_relay, HIGH);
        sendTelegramNotification(String("ID ") + userName + String(" berhasil membuka loker"));
        Serial.println(String("ID Tag ") + userName + String(" berhasil membuka loker"));
        digitalWrite(GREEN_PIN, LOW);
    } else {
        lcd.clear();
        lcd.print("Akses Ditolak");  // Display "Akses Ditolak" on LCD
        Serial.println(F("Akses ditolak"));
        digitalWrite(BUZZER_PIN, HIGH);
        digitalWrite(RED_PIN, HIGH);
        delay(2000);
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(RED_PIN, LOW);
        Serial.println("ID Tidak dikenal mencoba membuka loker");
        sendTelegramNotification("User tidak dikenal mencoba membuka loker,akses ditolak");
    }
}
