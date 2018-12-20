#include <EasyAPI.h>

API_Varable varablesSub1[1] = {{"g28",NULL,0}};
API_Varable varables[1] = {{"g28",varablesSub1,1}};
API api(1,varables);

void setup()
{
  //api.begin();
}

void loop() 
{
  
}