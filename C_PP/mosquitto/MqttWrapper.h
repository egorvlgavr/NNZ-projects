/* 
 * File:   MqttWrapper.h
 * Author: egor
 *
 * Created on 22 October 2015, 12:18
 */

#ifndef MQTTWRAPPER_H
#define	MQTTWRAPPER_H

#include <mosquittopp.h>

class MqttWrapper : public mosqpp::mosquittopp {
public:
    MqttWrapper(const std::string& id, const std::string& host, int port);
    ~MqttWrapper();

    // Actions   
    bool subscribeToTopic(const std::string& topicName);
    bool publishMessage(const std::string& topic, const std::string& message);

    // Event handlers
    void on_connect(int rc);
    void on_message(const struct mosquitto_message *message);
    void on_subscribe(int mid, int qos_count, const int *granted_qos);
private:
    const int keepalive_ = 100;
    const int qos_ = 0;
    
};

#endif	/* MQTTWRAPPER_H */

