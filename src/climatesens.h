
#ifndef climatesens_h
#define climatesens_h

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <ESPaccess.h>

struct SensorVarables {
    String Name;
    double value;
}

class climatesens
{
    public:
        // SETUP 
        climatesens(String _DeviceId,String _DeviceKey,SensorVarables *_sensor,int _sensorCount);

        void begin();
        void begin(String _name);
        void begin(String _name,String _password);
        
        void setPeriod(unsigned long _seconds);
        bool run();
        bool send();
        
    private:
        SensorVarables *sensor;
        int sensorCount; 
        ESPaccess connection;
        String name = "Climate Sens";
        String DeviceId;
        String DeviceKey;
        unsigned long periodSeconds;
};

#endif 
