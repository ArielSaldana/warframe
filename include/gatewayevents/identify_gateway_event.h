//
// Created by Ariel Saldana on 6/10/23.
//

#ifndef WARFRAME_IDENTIFY_GATEWAY_EVENT_H
#define WARFRAME_IDENTIFY_GATEWAY_EVENT_H

#include <iostream>
#include <string>
#include "serializable.h"

struct IdentifyGatewayEventProperties {
    std::string os;
    std::string browser;
    std::string device;
};

struct IdentifyGatewayEvent : public Serializable {
    std::string token;
    int intents;
    IdentifyGatewayEventProperties properties;

//    IdentifyGatewayEvent() : token(""), intents(0) {
//        properties.os = "";
//        properties.browser = "";
//        properties.device = "";
//    }

    IdentifyGatewayEvent(const std::string &tokenValue,
                         int intentsValue,
                         const IdentifyGatewayEventProperties &propertiesValue)
            : token(tokenValue), intents(intentsValue), properties(propertiesValue) {}

    std::string serialize() override {
        rapidjson::Document document;
        document.SetObject();

        rapidjson::Value tokenValue(token.c_str(), document.GetAllocator());
        document.AddMember("token", tokenValue, document.GetAllocator());

        document.AddMember("intents", intents, document.GetAllocator());

        rapidjson::Value propertiesValue(rapidjson::kObjectType);
        propertiesValue.AddMember("os", rapidjson::Value(properties.os.c_str(), document.GetAllocator()).Move(),
                                  document.GetAllocator());
        propertiesValue.AddMember("browser",
                                  rapidjson::Value(properties.browser.c_str(), document.GetAllocator()).Move(),
                                  document.GetAllocator());
        propertiesValue.AddMember("device", rapidjson::Value(properties.device.c_str(), document.GetAllocator()).Move(),
                                  document.GetAllocator());
        document.AddMember("properties", propertiesValue, document.GetAllocator());

        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
        document.Accept(writer);

        return buffer.GetString();
    }
};

#endif //WARFRAME_IDENTIFY_GATEWAY_EVENT_H
