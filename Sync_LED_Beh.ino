/*
This code is designed to synchronize Photometry data with behavior videos.
It operates by activating an LED for 2 seconds and sending a TTL pulse to the Photometry system, both synchronized to occur every 30 seconds.

IMPORTANT:
Ensure that the LED is connected to digital port 7 and the BNC cable is connected to digital port 8.

Aguiar - Braga, 08/14/2023 
*/

int ledPin = 13; 
int LedCam = 7; // LED
int SyncP = 8;  // Sync TTL

const unsigned long ONE_SECOND = 1000UL; 
const unsigned long F_DELAY = 30UL * ONE_SECOND; //The interval between TTL, here it is set to 30s.

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(LedCam, OUTPUT);
  pinMode(SyncP, OUTPUT);

  Serial.begin(9600);
}

void TTL2(void)
{
  Serial.println("TTL2");

  for (int trial = 1; trial <= 500; trial++)
  {
    Serial.println(trial);
    digitalWrite(ledPin, HIGH);
    digitalWrite(LedCam, HIGH);
    digitalWrite(SyncP, HIGH);

    delay(2000); // The duration of the TTL is 2 seconds.

    digitalWrite(ledPin, LOW);
    digitalWrite(LedCam, LOW);
    digitalWrite(SyncP, LOW);

    delay(F_DELAY);
  }
}

void loop()
{
  Serial.println("Programa iniciado");
  // delay(F_DELAY);
  TTL2();
}
