
#ifndef ESPaccess_h
#define ESPaccess_h

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#ifdef ESP32
    // ESP32 WIFI stack
#else
    #include <ESP8266WiFi.h>
    #include <ESP8266WiFiMulti.h>
    #include <ESP8266HTTPClient.h>
    #include <WiFiClientSecureBearSSL.h>
#endif


enum request_method {
    POST,
    GET,
    OPTIONS,
    HEAD,
    PUT,
    DELETE,
    TRACE,
    CONNECT,
    PATCH
};
/*
enum Device_Type {
    AP,
    AP_Client,
    AP_Server,
};*/

class ESPaccess
{
    public:
        // SETUP 
        ESPaccess(String _name,String _password);
        ESPaccess(String _name);
        void begin();

        // GET 
        void accessPoint();

        // GEN 
        int SendJson(string url,string request);
        int SendJson(request_method method,string url,string request);


        String HttpResponce;
        
    private:

};

#endif 
