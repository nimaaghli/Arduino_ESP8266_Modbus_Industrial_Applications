#include <ESP8266WiFi.h>
#include <ModbusTCPSlave.h>
#include <Ticker.h>

ModbusTCPSlave Mb;
Ticker tik;


void setup()
{
 
  Mb.begin("user", "pass");

  delay(1000);
  Mb.MBInputRegister[0] = 100;
  Mb.MBInputRegister[1] = 65500;
  Mb.MBInputRegister[2] = 300;
  Mb.MBInputRegister[3] = 400;
  Mb.MBInputRegister[4] = 500;

  Mb.MBHoldingRegister[0] = 1;
  Mb.MBHoldingRegister[1] = 2;
  Mb.MBHoldingRegister[2] = 3;
  Mb.MBHoldingRegister[3] = 4;
  Mb.MBHoldingRegister[4] = 5;
  tik.attach(1, update);
}

void loop()
{
 
  Mb.Run();
  delay(10);
                     
}
void update(){
    Mb.MBHoldingRegister[4] = random(1, 50) ;
}
/*****FUNZIONI*****/

byte checkRSSI() {
  byte quality;
  long rssi = WiFi.RSSI();
  if (rssi <= -100)
    quality = 0;
  else if (rssi >= -50)
    quality = 100;
  else
    rssi = rssi + 100;
  quality = byte(rssi * 2);

  return quality;
}


