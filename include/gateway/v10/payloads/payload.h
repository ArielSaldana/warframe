//
// Created by Ariel Saldana on 6/12/23.
//

#ifndef WARFRAME_PAYLOAD_H
#define WARFRAME_PAYLOAD_H

#include "payload-data.h"
#include "rapidjson/document.h"
#include <string>
#include <iostream>
#include "hello.h"

struct Payload {
    int op;
    PayloadData d;
    int s;
    std::string t;

public:
    static Payload deserialize(const rapidjson::Value& json) {
        Payload payload;

        if (json.HasMember("op") && json["op"].IsInt())
            payload.op = json["op"].GetInt();

        if (payload.op == 10) {
            std::cout << "Attempting to deserialize hello gateway event" << std::endl;
            //if (std::is_same<T, HelloGatewayEvent>::value) {
            if (json.HasMember("d") ) {
                auto data = json["d"].GetObj();
                HelloGatewayEvent ev;
                ev.deserialize(data);
//                auto hello_gateway_event = HelloGatewayEvent().deserialize(data);
                std::cout << ev.heartbeat_interval << std::endl;
//                HelloGatewayEvent hello{.heartbeat_interval = data["heartbeat_interval"].GetInt()};
//                p.d = hello;

            }
        }
        // Deserialize the d member based on its type
        // ...

        if (json.HasMember("s") && json["s"].IsInt())
            payload.s = json["s"].GetInt();

        if (json.HasMember("t") && json["t"].IsString())
            payload.t = json["t"].GetString();

        return payload;
    }
};

#endif //WARFRAME_PAYLOAD_H
