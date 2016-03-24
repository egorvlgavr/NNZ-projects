/* 
 * File:   MqttWrapper.cpp
 * Author: egor
 * 
 * Created on 22 October 2015, 12:18
 */

#include <string>
#include <iostream>

#include "MqttWrapper.h"
#include <mosquittopp.h>

MqttWrapper::MqttWrapper(const std::string& id, const std::string& host,
        int port) : mosquittopp(id.c_str()) {
    mosqpp::lib_init();
    // Set last will message it will be send if client be emergency disconnected 
    will_set(STATUS_TOPIC_, std::char_traits<char>::length(OFFLINE_MESSAGE_),
            OFFLINE_MESSAGE_, 0, true);
    connect(host.c_str(), port, keepalive_);
    publish(NULL, STATUS_TOPIC_, std::char_traits<char>::length(ONLINE_MESSAGE_),
            ONLINE_MESSAGE_, 0, true);
};

MqttWrapper::~MqttWrapper() {
    publish(NULL, STATUS_TOPIC_, std::char_traits<char>::length(OFFLINE_MESSAGE_),
                OFFLINE_MESSAGE_, 0, true);
    mosqpp::lib_cleanup();
}

void MqttWrapper::on_connect(int rc) {
    std::cout << "Connected with code " << rc << std::endl;
}

void MqttWrapper::on_message(const struct mosquitto_message *message) {
    std::string mqttTopic(message->topic);
    std::string messageData(static_cast<char*> (message->payload));
    std::cout << "Get message from topic: " + mqttTopic << std::endl;
    std::cout << "Message data: " + messageData << std::endl;

}

void MqttWrapper::on_subscribe(int mid, int qos_count, const int *granted_qos) {
    std::cout << "Subscription succeeded" << std::endl;
}

bool MqttWrapper::publishMessage(const std::string& topic, const std::string& message) {
    int res = publish(NULL, topic.c_str(), message.length(), message.c_str(), qos_);
    return (res == MOSQ_ERR_SUCCESS);
}

bool MqttWrapper::subscribeToTopic(const std::string& topicName) {
    int res = subscribe(NULL, topicName.c_str());
    return (res == MOSQ_ERR_SUCCESS);
}


