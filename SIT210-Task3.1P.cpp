// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>



DHT dht(A0,DHT11);

int led = D7; // Set Pin D7 as led 
int photodiode = A0;

void setup() {
    pinMode(led, OUTPUT); // D7 pin in-built LED
    dht.begin();

}

void loop() {
     
    digitalWrite(led,HIGH); // Turn on in-built LED 
    float temp = dht.getTempCelcius(); // Get Tempreture in Celcius
    Particle.publish("temp",String(temp),PRIVATE); // Trigger the Webhook - Puplish event to Cloud
    delay(30s); // Wait for 30 second
    
    // Turn Off LED for 30 Second
    digitalWrite(led,LOW);  // Turn Off LED
    delay(30s); // Wait for 30 Second

}
