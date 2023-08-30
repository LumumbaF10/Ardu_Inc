#include <Arduino.h>
#include "DHT.h"
#include <DHT_U.h>

#define DHTPIN 4

#define DHTTYPE DHT11

DHT dht (DHTPIN, DHTTYPE);

unsigned long previous_time = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Initializing the tempreture sensor......");
  dht.begin();
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  }

void loop() {
   //put your main code here, to run repeatedly: 
   digitalWrite(12,HIGH);
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  unsigned long  Current_time = millis();
  if(  (Current_time - previous_time) >= 60000)
  {
    digitalWrite(12,HIGH);

    delay(5000);

    previous_time = Current_time;
  }
  else
  {
    digitalWrite(12,LOW);
  }
  
  if (isnan(h) || isnan(t) )
  {
    Serial.println("Failed to read the tempreture and humidity!!");
    return;
  }
  
  Serial.print("Humidty:");
  Serial.print(h);
  Serial.println("%\t");
  Serial.println("..............................");
  Serial.print("Tempreture:");
  Serial.print(t);
  Serial.println("*C");
  Serial.println("..............................");
  
  delay(1000); 

if (t>=40)
  {
    digitalWrite(10,LOW);
  }
  else
  {
    digitalWrite(10,HIGH);
  }

if (h>=75)
{
  Serial.println("High humidity!!");
}

}