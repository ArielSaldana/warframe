//
// Created by Ariel Saldana on 6/13/23.
//

#ifndef WARFRAME_IDENTIFY_H
#define WARFRAME_IDENTIFY_H

#include <iostream>
#include <string>
#include "payload-data.h"
#include "../serializable.h"

struct Properties: public Serializable {
    std::string os;
    std::string browser;
    std::string device;

    rapidjson::Value serialize() override {
        rapidjson::Document document;
        rapidjson::Value values(rapidjson::kObjectType);

        values.AddMember("os", rapidjson::StringRef(os.c_str()), document.GetAllocator());
        values.AddMember("browser", rapidjson::StringRef(browser.c_str()), document.GetAllocator());
        values.AddMember("device", rapidjson::StringRef(device.c_str()), document.GetAllocator());

        return values;
    }
};

struct Identify: public PayloadData, Serializable {
    std::string token;
    int intents;
    Properties properties;

    rapidjson::Value serialize() override {
        rapidjson::Document document;
        document.SetObject();

        rapidjson::Value value(rapidjson::kObjectType);

        rapidjson::Value tokenValue(token.c_str(), rapidjson::SizeType(token.length()), document.GetAllocator());
        value.AddMember("token", tokenValue, document.GetAllocator());

        value.AddMember("intents", intents, document.GetAllocator());

        rapidjson::Value propertiesValue = properties.serialize();
        value.AddMember("properties", propertiesValue, document.GetAllocator());

        return std::move(value);
    }
};

#endif //WARFRAME_IDENTIFY_H
