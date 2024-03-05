#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
int calibrationTime = 10;
DHT dht(DHTPIN, DHTTYPE);

const int ldr_pin = 3;
const int led_pin = 2;
const int motionSensorPin = 6; 
const int ledPin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(motionSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ldr_pin,INPUT);
  pinMode(led_pin,OUTPUT);
  dht.begin();
}

void loop() {
  int motionState = digitalRead(motionSensorPin);
  float humi  = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  char status[4];
  delay(200);

  if (motionState == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(ledPin, HIGH); 
    if( digitalRead( ldr_pin ) == 1){
      digitalWrite( led_pin,HIGH);
      strcpy(status, "on");
   }
   else{
      digitalWrite( led_pin , LOW);
       strcpy(status, "off");
   }

  
  if (isnan(humi) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  "); 

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C ~ ");
    Serial.print(tempF);
    Serial.print("°F");

      Serial.print("  |  "); 

    Serial.print("LED Status: ");
    Serial.println(status);
  } 
  } else {
    Serial.println("No motion detected");
    digitalWrite(ledPin, LOW); // Turn off the LED
    ldr_pin == 0;
    digitalWrite( led_pin , LOW);
    strcpy(status, "off");
  }
  
  
}

bool isDaytime() {
  
  return true;
}
