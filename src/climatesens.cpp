/**********************************************************************************************
 * Arduino climatesens Library - Version 1.0
 * by William Bailes <williambailes@gmail.com> http://tinkersprojects.com/
 *
 * This Library is licensed under a GPLv3 License
 **********************************************************************************************/


#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "climatesens.h"


/******************* SETUP *******************/

climatesens::climatesens(String _DeviceId,String _DeviceKey,SensorVarables *_sensor,int _sensorCount)
{
  DeviceId = _DeviceId;
  DeviceKey = _DeviceKey;
  sensor = _sensor;
  sensorCount = _sensorCount;
}

void climatesens::begin()
{
  connection = new ESPaccess(name);
}

void climatesens::begin(String _name)
{
  name = _name;
  connection = new ESPaccess(_name);
}

void climatesens::begin(String _name,String _password)
{
  name = _name;
  connection = new ESPaccess(_name, _password);
}

void climatesens::setPeriod(unsigned long _seconds)
{
  sensorCount = _seconds;
}

void climatesens::run()
{
  this->send();
  delay(sensorCount*1000); // fix this
  //ADD connection.accessPoint();
}

bool climatesens::send()
{
  String httpRequest = "{\"key\":\""+DeviceKey+"\",\"id\":\""+DeviceId+"\",\"readings\":{";
  for (int i = 0; i < sensorCount; i++)
  {
    if(i != 0)
    httpRequest += ","
    httpRequest += "\""+sensor[i].name+"\":\""+sensor[i].value+"\"";
  }
  httpRequest += "}}";

  int httpCode =  connection.SendJson("https://api.climatesens.online/device",httpRequest);
  if(httpCode == 200)
    return true;
  return false;
}  