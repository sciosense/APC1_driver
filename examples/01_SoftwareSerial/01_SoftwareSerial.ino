#include <Arduino.h>
#include <SoftwareSerial.h>

#include <apc1.h>

using namespace ScioSense;

const uint8_t rxPin = 7;
const uint8_t txPin = 8;
SoftwareSerial softwareSerial(rxPin, txPin);
APC1 apc1;

void setup()
{
    Serial.begin(9600);
    Serial.println("");

    // Enable Debug if needed
    // apc1.enableDebugging(Serial);

    softwareSerial.begin(9600);
    apc1.begin(softwareSerial);

    if (apc1.isConnected() == false)
    {
        Serial.println("Error -- The APC1 is not connected.");
        while(1);
    }

    Serial.print("APC1 FW version: ");
    Serial.println(apc1.getFirmwareVersion());
}

void loop()
{
    if (apc1.update() == APC1::Result::Ok)
    {
        Serial.print("PM1.0: ");
        Serial.println(apc1.getPM_1_0());

        Serial.print("PM2.5: ");
        Serial.println(apc1.getPM_2_5());

        Serial.print("PM10: ");
        Serial.println(apc1.getPM_10());

        Serial.print("PM1.0 in air: ");
        Serial.println(apc1.getPMInAir_1_0());

        Serial.print("PM2.5 in air: ");
        Serial.println(apc1.getPMInAir_2_5());

        Serial.print("PM10 in air: ");
        Serial.println(apc1.getPMInAir_10());

        Serial.print("# particles >0.3μm: ");
        Serial.println(apc1.getNoParticles_0_3());

        Serial.print("# particles >0.5μm: ");
        Serial.println(apc1.getNoParticles_0_5());

        Serial.print("# particles >1.0μm: ");
        Serial.println(apc1.getNoParticles_1_0());

        Serial.print("# particles >2.5μm: ");
        Serial.println(apc1.getNoParticles_2_5());

        Serial.print("# particles >5.0μm: ");
        Serial.println(apc1.getNoParticles_5_0());

        Serial.print("# particles >10μm: ");
        Serial.println(apc1.getNoParticles_10());

        Serial.print("TVOC: ");
        Serial.println(apc1.getTVOC());

        Serial.print("ECO2: ");
        Serial.println(apc1.getECO2());

        Serial.print("T-comp.: ");
        Serial.println(apc1.getCompT());

        Serial.print("RH-comp.: ");
        Serial.println(apc1.getCompRH());

        Serial.print("T-raw: ");
        Serial.println(apc1.getRawT());

        Serial.print("RH-raw: ");
        Serial.println(apc1.getRawRH());

        Serial.print("RS0: ");
        Serial.println(apc1.getRS0());

        Serial.print("RS1: ");
        Serial.println(apc1.getRS1());

        Serial.print("RS2: ");
        Serial.println(apc1.getRS2());

        Serial.print("RS3: ");
        Serial.println(apc1.getRS3());

        Serial.print("AQI: ");
        Serial.print(apc1.getAQIString());
        Serial.print(" ");
        Serial.println((uint8_t)apc1.getAQI());

        Serial.print("Error code: ");
        Serial.println((uint8_t)apc1.getError(), BIN);

        Serial.println("-----------------------");
    }

    delay(1000);
}