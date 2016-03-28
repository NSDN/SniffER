#include <SPI.h>
#include <Wire.h>
#include <EEPROM.h>
#define VERSION F("V2.1")

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_DC     2
#define OLED_CS     3
#define OLED_RESET  9
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);
const static uint8_t PROGMEM LOGO[] =
{
    0x00,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x3F,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xFC,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x07,0xE0,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x1F,0x80,0x01,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xFE,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x03,0xF0,0x00,0x00,0x0F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x0F,0xC0,0x00,0x00,0x03,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x7E,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x78,0x00,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xE0,0x00,0x00,0x00,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xE0,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xC0,0x00,0x00,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x01,0xC0,0x00,0x00,0x00,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x01,0x80,0x00,0x01,0x80,0x01,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x03,0x80,0x00,0x07,0xF0,0x03,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x03,0x80,0x00,0x3F,0xFC,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x03,0x00,0x00,0xFC,0x3F,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x07,0x00,0x07,0xE0,0x07,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x06,0x00,0x0F,0x80,0x01,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x0E,0x00,0x1E,0x00,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x0C,0x00,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x0C,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x1C,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x18,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x38,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x30,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x70,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x70,0x00,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x60,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xE0,0x01,0xC0,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xE0,0x01,0xC0,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xE0,0x00,0xC0,0x00,0xF0,0x07,0x80,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xF0,0x00,0xE0,0x00,0x70,0x07,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xF0,0x00,0xE0,0x00,0x3C,0x07,0x00,0x0F,0xFF,0xFC,0xF3,0x83,0x07,0xCF,0x3F,0xFF,
    0xF0,0x00,0x60,0x00,0x1E,0x0E,0x00,0x0F,0xFF,0xFC,0x73,0x03,0x01,0xC7,0x3F,0xFF,
    0xF8,0x00,0x70,0x00,0x0F,0x0E,0x00,0x1F,0xFF,0xFC,0x33,0x3F,0x38,0xC3,0x3F,0xFF,
    0xF8,0x00,0x30,0x00,0x07,0x9C,0x00,0x1F,0xFF,0xFC,0x33,0x1F,0x3C,0xC3,0x3F,0xFF,
    0xFC,0x00,0x38,0x00,0x03,0x9C,0x00,0x3F,0xFF,0xFC,0x93,0x0F,0x3C,0xC9,0x3F,0xFF,
    0xFC,0x00,0x18,0x00,0x01,0xF8,0x00,0x3F,0xFF,0xFC,0x83,0xC3,0x3C,0xC8,0x3F,0xFF,
    0xFC,0x00,0x1C,0x00,0x00,0xF8,0x00,0x3F,0xFF,0xFC,0xC3,0xE3,0x3C,0xCC,0x3F,0xFF,
    0xFE,0x00,0x1C,0x00,0x00,0x78,0x00,0x7F,0xFF,0xFC,0xE3,0xF3,0x38,0xCE,0x3F,0xFF,
    0xFE,0x00,0x0F,0x80,0x01,0xF8,0x00,0x7F,0xFF,0xFC,0xE3,0x03,0x01,0xCE,0x3F,0xFF,
    0xFF,0x00,0x07,0xE0,0x07,0xFC,0x00,0xFF,0xFF,0xFC,0xF3,0x07,0x07,0xCF,0x3F,0xFF,
    0xFF,0x00,0x00,0xFC,0x3F,0x0E,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x80,0x00,0x3F,0xFC,0x07,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x80,0x00,0x0F,0xF0,0x03,0x81,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x80,0x00,0x01,0x80,0x01,0xC1,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xC0,0x00,0x00,0x00,0x00,0xE3,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xC0,0x00,0x00,0x00,0x00,0x73,0xFF,0xFF,0xE7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xE0,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xE7,0xFF,0xFC,0xE3,0x90,0x3F,0x3F,
    0xFF,0xE0,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFE,0x67,0xFF,0xFC,0xE3,0x90,0x1F,0x3F,
    0xFF,0xF8,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFE,0x67,0xF9,0xFC,0xE3,0x93,0x8F,0x3F,
    0xFF,0xFE,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFC,0x20,0x60,0xFC,0x41,0x13,0xCF,0x3F,
    0xFF,0xFF,0xC0,0x00,0x00,0x03,0xFF,0xFF,0xFC,0x20,0x26,0x7E,0x49,0x33,0xC7,0x3F,
    0xFF,0xFF,0xF0,0x00,0x00,0x0F,0xFF,0xFF,0xFE,0x67,0x26,0x7E,0x49,0x33,0xC7,0x3F,
    0xFF,0xFF,0xFC,0x00,0x00,0x3F,0xFF,0xFF,0xFE,0x67,0x20,0x7E,0x49,0x33,0xCF,0x3F,
    0xFF,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0xFF,0xFE,0x67,0x27,0xFE,0x1C,0x73,0x8E,0x3F,
    0xFF,0xFF,0xFF,0xE0,0x07,0xFF,0xFF,0xFF,0xFE,0x27,0x30,0x7F,0x1C,0x70,0x18,0x7F,
    0xFF,0xFF,0xFF,0xFC,0x3F,0xFF,0xFF,0xFF,0xFF,0x27,0x38,0xFF,0x1C,0x70,0x78,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN  4
DHT DHT(DHTPIN, DHTTYPE);
float TemperDHT, HumiDHT;

#include <Adafruit_BMP085.h>
#define SURFPRESS_ADDR 0x0
Adafruit_BMP085 BMP;
static float SurfPressure;
float TemperBMP, PressureBMP, AltitudeBMP;

#include <MFRC522.h>
#define RST_PIN         9
#define SS_PIN          10
MFRC522 mfrc522(SS_PIN, RST_PIN);
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        display.print(buffer[i] < 0x10 ? " 0" : " ");
        display.print(buffer[i], HEX);
    }
}
boolean try_key(MFRC522::MIFARE_Key *key)
{
    boolean result = false;
    byte buffer[18];
    byte block = 0;
    byte status;
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(31, 0);
    display.setTextColor(BLACK, WHITE);
    display.println(F("RFID Crack"));
    display.setTextColor(WHITE);
    display.setCursor(0, 16);
    display.println(F("Auth with key:"));
    dump_byte_array((*key).keyByte, MFRC522::MF_KEY_SIZE);
    display.display();
    
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        return false;
    }

    // Read block
    byte byteCount = sizeof(buffer);
    status = mfrc522.MIFARE_Read(block, buffer, &byteCount);
    if (status == MFRC522::STATUS_OK) {
        // Successful read
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(31, 0);
        display.setTextColor(BLACK, WHITE);
        display.println(F("RFID Crack"));
        display.setTextColor(WHITE);
        display.setCursor(0, 16);    
        result = true;
        display.print(F("Success with key:"));
        dump_byte_array((*key).keyByte, MFRC522::MF_KEY_SIZE);
        display.println();
        // Dump block data
        display.print(F("Block ")); display.print(block); display.print(F(":"));
        dump_byte_array(buffer, 16);
        display.println();
        display.display();
        delay(2000);
    }
    
    mfrc522.PICC_HaltA();       // Halt PICC
    mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
    return result;
}

/*
 * Keyboard Begin *
    UP      A1-A6
    DOWN    A3-A7
    LEFT    A1-A7
    RIGHT   A3-A6
    OK      A2-A7
    CANCEL  A2-A6
 *  KeyBoard End  *
 */
//static int tmpTime = 0;
/*
    if ((GetKey() & KEY_UP) | (GetKey() & KEY_LEFT)) {
        if (tmpTime == 0) tmpTime = millis();
        while ((GetKey() & KEY_UP) | (GetKey() & KEY_LEFT)) {
            if (millis() - tmpTime > 1000) {
                delay(50);
                break;
            }
        }
        menuIndex--;
    } else tmpTime = 0;
*/

int8_t menuIndex = 1;
#define KEY_UP      B00000001
#define KEY_DOWN    B00000010
#define KEY_LEFT    B00000100
#define KEY_RIGHT   B00001000
#define KEY_OK      B00010000
#define KEY_CANCEL  B00100000
boolean Convert(int Data) {
    return Data == 1023 ? true : false;
}
uint8_t GetKey() {
    uint8_t tmpVal = 0;
    
    digitalWrite(A1, HIGH);
    if (Convert(analogRead(A6)) || Convert(analogRead(A7)))
        delay(10);
    tmpVal |= Convert(analogRead(A6)) ? KEY_UP : 0;
    tmpVal |= Convert(analogRead(A7)) ? KEY_LEFT : 0;
    digitalWrite(A1, LOW);

    digitalWrite(A2, HIGH);
    if (Convert(analogRead(A6)) || Convert(analogRead(A7)))
        delay(10);
    tmpVal |= Convert(analogRead(A6)) ? KEY_CANCEL : 0;
    tmpVal |= Convert(analogRead(A7)) ? KEY_OK : 0;
    digitalWrite(A2, LOW);

    digitalWrite(A3, HIGH);
    if (Convert(analogRead(A6)) || Convert(analogRead(A7)))
        delay(10);
    tmpVal |= Convert(analogRead(A6)) ? KEY_RIGHT : 0;
    tmpVal |= Convert(analogRead(A7)) ? KEY_DOWN : 0;
    digitalWrite(A3, LOW);

    return tmpVal;
}

void showLogo() {
    display.clearDisplay();
    display.drawBitmap(0, 0, LOGO, 128, 64, 1);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(84, 0);
    display.println(F("SniffER"));
    display.setCursor(93, 8);
    display.println(VERSION);
    display.display();
}

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC);
    
    showLogo();
    delay(2000);
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.print(F("[INIT] BMP085"));
    if (!BMP.begin()) {
        display.println(F(";ERROR"));
    }
    else {
        display.println(F(";DONE"));
    }
    
    display.print(F("[INIT] MFRC522"));
    mfrc522.PCD_Init();
    display.println(F(";DONE"));

    display.print(F("[INIT] KEYBRD"));
    pinMode(A6, INPUT);
    pinMode(A7, INPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    display.println(F(";DONE"));

    display.print(F("[LOAD] Config"));
    EEPROM.get(SURFPRESS_ADDR, SurfPressure);
    display.println(F(";DONE"));
    
    display.display();
    delay(2000);
}

void EnvSniff()
{
    TemperDHT = DHT.readTemperature();
    HumiDHT = DHT.readHumidity();
    TemperBMP = BMP.readTemperature();
    PressureBMP = (float)BMP.readPressure() / 1000.0;
    AltitudeBMP = BMP.readAltitude(SurfPressure * 100.0);
    //AltitudeBMP = BMP.readAltitude(105000);
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(34, 0);
    display.setTextColor(BLACK, WHITE);
    display.println(F("Env. Sniff"));
    display.setTextColor(WHITE);
    
    display.setCursor(0, 16);
    
    display.print(F("TemperDHT="));
    display.print(TemperDHT);
    display.println(F("*C"));
    
    display.print(F("HumiDHT="));
    display.print(HumiDHT);
    display.println(F("%"));
    
    display.print(F("TemperBMP="));
    display.print(TemperBMP);
    display.println(F("*C"));
    
    display.print(F("PressureBMP="));
    display.print(PressureBMP);
    display.println(F("kPa"));
    
    display.print(F("AltitudeBMP="));
    display.print(AltitudeBMP);
    display.println(F("m"));
    
    display.display();

    delay(200);
}

void EnvConfig() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(28, 0);
    display.setTextColor(BLACK, WHITE);
    display.println(F("Env. Config"));
    display.setTextColor(WHITE);
    display.setCursor(0, 16);
    display.println(F("Surface Pressure:"));
    display.print(SurfPressure);
    display.println(F(" hPa"));
    display.display();

    if ((GetKey() & KEY_UP) | (GetKey() & KEY_LEFT)) {
        //while ((GetKey() & KEY_UP) | (GetKey() & KEY_LEFT));
        delay(50);
        SurfPressure++;
    }
    if ((GetKey() & KEY_DOWN) | (GetKey() & KEY_RIGHT)) {
        //while ((GetKey() & KEY_DOWN) | (GetKey() & KEY_RIGHT));
        delay(50);
        SurfPressure--;
    }

    if (GetKey() & KEY_OK) {
        while (GetKey() & KEY_OK);
        EEPROM.put(SURFPRESS_ADDR, SurfPressure);
        display.setCursor(0, 54);
        display.println(F("SAVED"));
        display.display();
        delay(500);
        menuIndex -= 10;
    }
}

void RFIDSniff() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(34, 0);
    display.setTextColor(BLACK, WHITE);
    display.println(F("RFID Sniff"));
    display.setTextColor(WHITE);
    display.setCursor(0, 16);
    display.println(F("Scanning..."));
    display.display();
    
    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    display.setCursor(0, 24);
    // Show some details of the PICC (that is: the tag/card)
    display.print(F("Card UID:"));
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    display.println();
    display.print(F("PICC type:"));
    byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    display.println(mfrc522.PICC_GetTypeName(piccType));

    display.display();

    while (mfrc522.PICC_ReadCardSerial());
}

void RFIDCrack() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(31, 0);
    display.setTextColor(BLACK, WHITE);
    display.println(F("RFID Crack"));
    display.setTextColor(WHITE);
    display.setCursor(0, 16);
    display.println(F("Scanning..."));
    display.display();

    // Look for new cards
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;
    
    display.println();    
    // Show some details of the PICC (that is: the tag/card)
    display.print(F("Card UID:"));
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    display.println();
    display.print(F("PICC type: "));
    byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    display.println(mfrc522.PICC_GetTypeName(piccType));
    display.display();
    delay(2000);

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(31, 0);
    display.setTextColor(BLACK, WHITE);
    display.println(F("RFID Crack"));
    display.setTextColor(WHITE);
    display.setCursor(0, 16);
        
    display.println(F("DO NOT PRESS"));
    display.println(F("  ANY KEY!"));
    display.display();
    
    // Try the known default keys
    MFRC522::MIFARE_Key key; int rndMax = 0, rndMin = 0;

    rndMin = analogRead(A6) + analogRead(A7);
    for (uint8_t i = 0; i < 100; i++) {
        rndMin = min(rndMin, analogRead(A6) + analogRead(A7));
        delay(10);
    }
    
    rndMax = analogRead(A6) + analogRead(A7);
    for (uint8_t i = 0; i < 100; i++) {
        rndMax = max(rndMax, analogRead(A6) + analogRead(A7));
        delay(10);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(31, 0);
    display.setTextColor(BLACK, WHITE);
    display.println(F("RFID Crack"));
    display.setTextColor(WHITE);
    display.setCursor(0, 16);
    display.println(F("Crack start!"));
    display.println(F("CANCEL to break"));
    display.display();
    delay(2000);
    
    
    while (true) {
        for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++) {
            key.keyByte[i] = (byte)map(analogRead(A6) + analogRead(A7), rndMin, rndMax, 0x00, 0xFF);
            delay(10);
        }
        // Try the key
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(31, 0);
        display.setTextColor(BLACK, WHITE);
        display.println(F("RFID Crack"));
        display.setTextColor(WHITE);
        display.setCursor(0, 16);
        if (try_key(&key)) {
            display.clearDisplay();
            display.setTextSize(1);
            display.setCursor(31, 0);
            display.setTextColor(BLACK, WHITE);
            display.println(F("RFID Crack"));
            display.setTextColor(WHITE);
            display.setCursor(0, 16);
            display.print(F("Success with key:"));
            dump_byte_array(key.keyByte, MFRC522::MF_KEY_SIZE);
            display.println();
            display.println(F("OK for return"));
            display.display();
            while (!(GetKey() & KEY_OK));
        }
        if (GetKey() & KEY_CANCEL) break;
    }
}

void buildMenu() {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(32, 0);
    display.setTextColor(BLACK, WHITE);
    display.println(F("SniffER V2.1"));
    display.setTextColor(WHITE);
    display.setCursor(24, 16);
    display.println(F("1.Env. Sniff"));
    display.setCursor(24, 24);
    display.println(F("2.Env. Config"));
    display.setCursor(24, 32);
    display.println(F("3.RFID Sniff"));
    display.setCursor(24, 40);
    display.println(F("4.RFID Crack"));
    display.setCursor(24, 48);
    display.println(F("5.About This"));
    
    if ((GetKey() & KEY_UP) | (GetKey() & KEY_LEFT)) {
        while ((GetKey() & KEY_UP) | (GetKey() & KEY_LEFT));
        menuIndex--;
    }
    if ((GetKey() & KEY_DOWN) | (GetKey() & KEY_RIGHT)) {
        while ((GetKey() & KEY_DOWN) | (GetKey() & KEY_RIGHT));
        menuIndex++;
    }

    if (menuIndex > 5) menuIndex = 1;
    if (menuIndex < 1) menuIndex = 5;
    
    display.setCursor(8, (menuIndex + 1) * 8);
    display.println(F("->"));
    display.display();
}

void loop() {
    switch (menuIndex) {
        case 11:
            EnvSniff();
            break;
        case 12:
            EnvConfig();
            break;
        case 13:
            RFIDSniff();
            break;
        case 14:
            RFIDCrack();
            break;
        case 15:
            showLogo();
            break;
        default:
            buildMenu();
            break;
    }

    if (GetKey() & KEY_OK) {
        while (GetKey() & KEY_OK);
        menuIndex += 10;
        while (menuIndex > 20) menuIndex -= 10;
    }

    if (GetKey() & KEY_CANCEL) {
        while (GetKey() & KEY_CANCEL);
        menuIndex -= 10;
        while (menuIndex < 0) menuIndex += 10;
    }
}
