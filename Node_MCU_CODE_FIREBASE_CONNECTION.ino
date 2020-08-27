
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <Wire.h>
#include "DHT.h" 

#define FIREBASE_HOST "tryd-549a6.firebaseio.com"
#define FIREBASE_AUTH "nbIxWnEZP8H1QuHnqRMy61P5syp7xzvFQ9X3DYGX"
#define WIFI_SSID "Chishtiin507"
#define WIFI_PASSWORD "Chishtiinbahria"
#define DHTTYPE DHT11
#define dht_dpin 0
DHT dht(dht_dpin, DHTTYPE); 
//Define FirebaseESP8266 data object
FirebaseData firebaseData;
uint8_t i;
FirebaseJson json;
int a=1;
int noise=0,temp=0,hum=0,bip=0;
void printResult(FirebaseData &data);

void setup()
{
Serial.begin(115200);
Wire.begin(D1, D2);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  dht.begin();
  Serial.println("------------------------------------");
  Serial.println("Uploading Started...");
 }
void loop()
{
String path = "/Sensors Data";
   Wire.requestFrom(8, 4);
 while(Wire.available()){
    
  if(a==1)
  {
  Serial.print("Smoke: ");
  noise = Wire.read();
  Serial.println(noise);
    json.set("Reading" + String(i), noise);
    if (Firebase.updateNode(firebaseData, path + "/Pollution", json))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      //No ETag available
      Serial.print("VALUE: ");
      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  Serial.println("------------------------------------");
  Serial.println("Update test...");
  
  a=2;
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(a==2)
  {  

  Serial.print("Temperature: ");
  temp = Wire.read();
  Serial.println(temp);

    json.set("Reading" + String(i), temp);

    
    if (Firebase.updateNode(firebaseData, path + "/Temperature", json))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      //No ETag available
      Serial.print("VALUE: ");
      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }

   Serial.println("------------------------------------");
  Serial.println("Update test..."); 
  a=3;
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

if(a==3)
  {  
    
 hum=0;
  Serial.print("Humudity: ");
  hum = Wire.read();
  Serial.println(hum);
  
    json.set("Reading" + String(i), hum);
hum=0;
    
    if (Firebase.updateNode(firebaseData, path + "/Humudity", json))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      //No ETag available
      Serial.print("VALUE: ");
      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }


  Serial.println("------------------------------------");
  Serial.println("Update test...");
  a=4;
 
  
 
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(a==4)
  {  

  Serial.print("bip: ");
  bip = Wire.read();
  Serial.println(bip);
 
    json.set("Reading" + String(i), bip);

    
    if (Firebase.updateNode(firebaseData, path + "/bip", json))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      //No ETag available
      Serial.print("VALUE: ");
      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }

  Serial.println("------------------------------------");
  Serial.println("Update test...");
  a=5;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(a==5)
  {  

  Serial.print("Humudity Outside: ");
 int h = dht.readHumidity();
  Serial.println(h);
 
    json.set("Reading" + String(i), h);

    
    if (Firebase.updateNode(firebaseData, path + "/Humudity Outside", json))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      //No ETag available
      Serial.print("VALUE: ");
      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }

  Serial.println("------------------------------------");
  Serial.println("Update test...");
  a=6;
  

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  if(a==6)
  {  

  Serial.print("Temperature Outside: ");
 int t = dht.readTemperature(); 
  Serial.println(t);
 
    json.set("Reading" + String(i), t);

    
    if (Firebase.updateNode(firebaseData, path + "/Temperture Outside", json))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      //No ETag available
      Serial.print("VALUE: ");
      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }

  Serial.println("------------------------------------");
  Serial.println("Update test...");
  a=7;
  
if(a==7)
  {  

  Serial.print("Alcohal Level ");
  Serial.println(noise);
int az=0;
if(noise>500)
{
  az=1;
  }
    json.set("Reading" + String(i), az);

    
    if (Firebase.updateNode(firebaseData, path + "/Alcohal", json))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      //No ETag available
      Serial.print("VALUE: ");
      Serial.println("------------------------------------");
      Serial.println();
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }


  Serial.println("------------------------------------");
  Serial.println("Update test...");
  a=1;
 
  }
   
}
