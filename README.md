# Commuction-bewteen-two-arduino-and-Node-MCU
Final Year Project is consist of 2 arduino and 1 node MCU. Both arduino are added in a way that

| Electronics Devices | Description |
| --- | --- |
| Arduino 1 | Slave Arduino which collect data from MAX30100 and Heartbeat Sensor |
| Arduino 2 | Master Arduino which collect data from Arduino 1, Humudity sensor and send all data to NODE MCU |
| Node MCU | Master controller which recieve data from Arduino 2 and upload all data to firebase |

This is the file(named as: Node_MCU_CODE_FIREBASE_CONNECTION) for controlling all data from two arduino. The data from different sensors transfer from slave arduino to master arduino and then master arduino send data to ESP-8266 NODE MCU. FOR communication between node MCU and Master arduino.

#include <Wire.h>

Header Wire.h used using port as mentioned below.

There is also a firebase connection which upload sensors data and this updated cloud data used for keeping people updated online at realtime bases.

Below Circuit Diagram:

![alt text](https://user-images.githubusercontent.com/24813204/91445643-d03f5400-e88f-11ea-9464-4287af5dea5d.png)

All files are avilaible here. So, you can use them for further changes. 

Two modes of Communction used:

| Electronics Devices | Communction Type |
| --- | --- |
| Arduino 1 to Arduino 2 | Serial Communication |
| Arduino 2 to Node MCU | Wire Communication |

Components Used:

| Electronics Devices |
| --- |
| Arduino 2 | 
| Node MCU ESP-8266| 
| Humudity Sensor DHT-11 2 | 
| Smoke Sensor MQ-2 | 
| HEART PULSE SENSOR | 
| MAX30100 | 



This is mine final year project but other part is quardcopter whose demo picture is attached below:

![alt text](https://user-images.githubusercontent.com/24813204/91445370-73439e00-e88f-11ea-8ba8-d9d79ce907b3.jpg)




