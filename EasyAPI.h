
#ifndef EasyAPI_h
#define EasyAPI_h

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

typedef struct API_Varable 
{
    String name;
    String *Value;
    API_Varable *API_Varables;
    int count;
};

class EasyAPI
{
    public:
        // SETUP 
        EasyAPI();
        EasyAPI(int numbercommands, API_Varable &_APIVarables);

        //make serial number
        void makeSerial();

        // GET 
        void getKey();
        String APIKey;

        // GEN 
        void JSON();
        void GET();
        void POST();
        
    private:
        API_Varable *APIVarables; 
};

#endif 
