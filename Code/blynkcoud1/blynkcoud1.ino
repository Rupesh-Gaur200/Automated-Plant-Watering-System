#define BLYNK_TEMPLATE_ID "TMPL3hXrknejh"
#define BLYNK_TEMPLATE_NAME "PlantWateringV2"
#define BLYNK_AUTH_TOKEN "lAwexIUQI-Rjb4M_PdXkkumwaxR2CkeX"
#include <BlynkSimpleEsp32.h>




void setup()
{Blynk.begin(BLYNK_AUTH_TOKEN, "JioFi3_50688C", "2u36kp9cma9");
 
  Serial.begin(115200);
  
}

void loop()
{
 
  Blynk.run();
}
