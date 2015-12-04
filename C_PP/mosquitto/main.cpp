/* 
 * File:   main.cpp
 * Author: egor
 *
 * Created on 22 October 2015, 13:30
 */

#include <string>
#include <iostream>


#include "MqttWrapper.h"

int main(int argc, char *argv[]) {
    MqttWrapper *mqtt_client;
    int rc;
    const std::string client_name("simpleClient");
    const std::string host("localhost");
    const int port = 1883;
    std::string topic_to_subscribe("test/listening");
    std::string topic_to_publish("test/saying");

    mqtt_client = new MqttWrapper(client_name.c_str(), host.c_str(), port);
    mqtt_client->subscribeToTopic(topic_to_subscribe);
    mqtt_client->publishMessage(topic_to_publish, "SimplePublication");

    while (true) {
        rc = mqtt_client->loop();
        if (rc) {
            mqtt_client->reconnect();
        }
    }
    delete mqtt_client;
    return 0;
}
