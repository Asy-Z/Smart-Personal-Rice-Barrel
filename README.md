# Purpose

Our smart personal rice barrel will be available to everyone as a household item
especially for the consumer market of Asia. The barrel will conveniently help user to
indicate and keep on close tab on their rice stocks. The system is included with
weight sensor which will detect the current weight of the rice. When the rice reduces
to 1kg of weight and load it will send an alert through push notification. It will also be
able to record and analyse the pattern of rice consumption for the user.

### Behaviour
The behaviour of the IoT rice storage system is characterized by a set of key features
and functionalities that aim to transform traditional rice storage into a smart and user-
friendly experience. It includes real-time monitoring of rice quantity using weight
sensor technology, allowing users to stay informed about the amount of rice they
have at any given time. The system also tracks consumption patterns, offering users
insights into their rice usage trends and providing predictive alerts when it's time to
replenish their rice supply. The system's behaviour is complemented by an intuitive
mobile app interface for user-friendly interaction, making it a seamless and
convenient solution for efficient rice storage management.

### System Management Requirement:
The system should provide real time monitoring system by application. Notification
will be sent to the user if the rice load is below 1kg.

### Data Analysis Requirement:
The system should perform cloud-based analysis of the data and uploaded to the
user application in the form of graph for the user to observe.

### Application Deployment Requirement:
Since the application is installed locally on the hardware, users may access and
manage the system with Wi-Fi connection both mobile devices and the rice barrel.

### Security Requirement:
The system is equipped with an off switch through the application, and it is single
user only.

## Process Specification

In the IoT design methodology, the second step involves defining the process
specification.

In the context of the Smart Personal Rice Barrel system when it is detecting
weightage lower than 1kg the system will be turned on automatically. If the weight
load detecting an additional weightage more than 1kg the system will be turned off by
itself. In manual mode, thru using the system application the user has the authority to the
power of the system whether to turn it on or off.

## Device Component Management

```
No. Components Quantity
1 NodeMCU 1
2 HX711 Cell Amplifier 1
3 Weight Sensor 1
4 Wire 9
```
```
Hardware Setup:
```
- Connect the HX711 module to the NodeMCU and the weight sensor as follows:
    - Connect VCC on the HX711 to the 3.3V output on the NodeMCU.
    - Connect GND on the HX711 to GND on the NodeMCU.
    - Connect DT (Data) on the HX711 to a GPIO pin on the NodeMCU
    - Connect SCK (Clock) on the HX711 to another GPIO pin on the NodeMCU
    - Connect the load cell to the HX711 module. The load cell wires typically have
       four colors: red (excitation+), black (excitation-), green (signal+), and white
       (signal-).
- Provide power to the NodeMCU, either via USB or an external power supply.

The mobile application is powered by Blynk
