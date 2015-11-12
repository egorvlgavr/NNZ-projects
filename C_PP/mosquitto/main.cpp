/* 
 * File:   main.cpp
 * Author: egor
 *
 * Created on 22 October 2015, 13:30
 */

#include <string>
#include <iostream>


#include "MqttWrapper.h"

int main(int argc, char *argv[])
{
	MqttWrapper *simpleClient;
	int rc;

	mosqpp::lib_init();
        
        const std::string mqttClientName("simpleClient"); 
        const std::string host("localhost");
        const int port = 1883;
        std::string topicToSubscribe("test/listening");
        std::string topicToPublish("test/saying");
        
	simpleClient = new MqttWrapper(mqttClientName.c_str(), host.c_str(), port);
        simpleClient->subscribeToTopic(topicToSubscribe);
        simpleClient->publishMessage(topicToPublish, "SimplePublication");
        
	while(1){
		rc = simpleClient->loop();
		if(rc){
                    simpleClient->reconnect();
		}
	}

	mosqpp::lib_cleanup();
        delete simpleClient;
	return 0;
}
