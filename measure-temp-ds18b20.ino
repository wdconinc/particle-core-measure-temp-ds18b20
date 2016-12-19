#include "OneWire.h"
#include "spark-dallas-temperature.h"

// -----------------
// Read temperature
// -----------------

DallasTemperature dallas(new OneWire(D7));;

void setup()
{
  dallas.begin();
}

void loop()
{
  dallas.requestTemperatures();
  String temp_DS18B20 = String(dallas.getTempCByIndex(0));
  Particle.publish("temp_DS18B20",temp_DS18B20,PRIVATE);

  delay(15000);
}

