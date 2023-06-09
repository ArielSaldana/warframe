//
// Created by Ariel Saldana on 6/13/23.
//

#ifndef WARFRAME_HELLO_H
#define WARFRAME_HELLO_H

#include "payload-data.h"
#include "../deserializable.h"

struct HelloGatewayEvent : public PayloadData, Deserializable<HelloGatewayEvent> {
    int heartbeat_interval{};

    HelloGatewayEvent() = default;
    
    explicit HelloGatewayEvent(const rapidjson::Value &json) {
        deserialize(json);
    }

    HelloGatewayEvent deserialize(const rapidjson::Value &json) override {
        HelloGatewayEvent hello_gateway_event;
        if (json.HasMember("heartbeat_interval") && json["heartbeat_interval"].IsInt()) {
//            event_data.heartbeat_interval = json["heartbeat_interval"].GetInt();
            heartbeat_interval = json["heartbeat_interval"].GetInt();
        }
        return hello_gateway_event;
    }
};

#endif //WARFRAME_HELLO_H
