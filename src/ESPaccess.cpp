/**********************************************************************************************
 * Arduino ESPaccess Library - Version 1.0
 * by William Bailes <williambailes@gmail.com> http://tinkersprojects.com/
 *
 * This Library is licensed under a GPLv3 License
 **********************************************************************************************/


#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "ESPaccess.h"


/******************* SETUP *******************/
ESPaccess::ESPaccess(String _name,String _password)
{

}

ESPaccess::ESPaccess(String _name)
{

}

void ESPaccess::begin()
{
  WiFi.mode(WIFI_STA);
}







/******************* ACCESS POINT *******************/

void ESPaccess::accessPoint()
{

}







/******************* SEND *******************/

/** send JSON */
int ESPaccess::SendJson(string url,string request)
{
  return this->SendJson(POST,url,request);
}

/** send JSON */
int ESPaccess::SendJson(request_method method,string url,string request)
{
  if (WiFi.status() == WL_CONNECTED) 
  {
    /*Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());*/
    
    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
    client->setInsecure();
    
    HTTPClient http;
    int httpCode = 0;
    if(http.begin(*client,url))
    {
      http.addHeader("Content-Type", "application/json");
      http.addHeader("Accept", "application/json");
      http.addHeader("HTTP_ACCEPT", "application/json");
  
      switch (method)
      {
      case POST:
        http.POST(request);
        break;
      
      case GET:
      default:
        http.GET(request);
        break;
      }

      HttpResponce = http.getString();  
      http.end();
      return httpCode;
    } 
    else 
    {
      //[HTTPS] Unable to connect
      http.end();
      return httpCode;
    }
  }
  else
  {
    //WiFi not connected!
    return -1;
  }
  return false;
}
   