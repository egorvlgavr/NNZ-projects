SimpleMosquittopp
=========
Simple exapmle of using libmosquittopp library.
Using MQTT broker on _localhost:1883_. Subscribe on topic **test/listening**, publish message in topic **test/saying**. Client status can be viewed in topic **test/status**. The Last Will and Testament (LWT) feature is used together with retained messages in this example.

Based on project Mosquitto. Mosquitto is an open source implementation of a server for version 3.1 and
3.1.1 of the MQTT protocol. Information is available at the following location:

- MQTT community page: <http://mqtt.org/> 
- Mosquitto project main homepage: <http://mosquitto.org/>  
- Full API of libmosquittopp: <http://mosquitto.org/api/files/mosquitto-h.html>

Tested on Linux Mint 17.1 'Rebecca' Mate 64bit  
IDE: NetBeans IDE 8.0.2 (Build 201411181905)


### Installation

Version of mosquitto and libries from Linux Mint repository isn't used because they are out of date.
So I advise to follow steps from: <http://goochgooch.co.uk/2014/08/01/building-mosquitto-1-4/>  
Latest version can be cloned from: <https://git.eclipse.org/r/mosquitto/org.eclipse.mosquitto>

### Using

Start Mosquitto  
```
# this steps need only first time you run broker
sudo iptables -A INPUT -p tcp -m tcp --dport 1883 -j ACCEPT #allow MQTT port
sudo /sbin/ldconfig #update list of lib files
```  
```
mosquitto #run MQTT broker
```

Start two subscribe clients 
```
mosquitto_sub -v -t 'test/saying'  
mosquitto_sub -v -t 'test/status'
```

Publish test message  
```
mosquitto_pub -t 'test/listening' -m 'Hello world!'
```
