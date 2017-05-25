#ifndef IOTDATAMQTT_H_
#define IOTDATAMQTT_H_

#include "aws_iot_config.h"
#include "aws_iot_log.h"
#include "aws_iot_version.h"
#include "aws_iot_mqtt_client_interface.h"
#include "aws_iot_shadow_interface.h"

#include "IotData.hpp"

using namespace std;

class IotDataMqtt : public IotData {
	
	AWS_IoT_Client mqttClient;
	char thingId[255];
	char thingName[255];

	const char* TAG = "shadow";

        // set in sdkconfig
	const char* HOST = CONFIG_AWS_IOT_MQTT_HOST;
	uint32_t PORT = CONFIG_AWS_IOT_MQTT_PORT;
	
        public:
	virtual int signup(char*,char*);
	virtual int init(char*);
	virtual int send(char*, size_t, jsonStruct_t*, int);
	virtual int sendraw(char*);
	virtual int close();

};

#endif

