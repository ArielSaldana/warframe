//
// Created by Ariel Saldana on 5/30/23.
//

#ifndef WARFRAME_GATEWAY_EVENT_PROCESSOR_H
#define WARFRAME_GATEWAY_EVENT_PROCESSOR_H

#include "gatewayevents/hello_gateway_event.h"
#include "payload.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <eventbus.h>
#include <iostream>
#include <string>
#include <utility>
#include "event-emitter/eventmessage.h"

class GatewayEventProcessor {

    EventBus eventbus;

    template<typename T>
    Payload<T> deserialize(const rapidjson::Document &json_doc) {
        if (std::is_same<T, HelloGatewayEvent>::value) {
            Payload<T> p;
            p.op = json_doc["op"].GetInt();

            auto data = json_doc["d"].GetObj();
            HelloGatewayEvent hello{.heartbeat_interval = data["heartbeat_interval"].GetInt()};
            p.d = hello;

            return p;
        }
    }

    std::pair<int, rapidjson::Document> peek_opcode(const std::string &payload_json) {
        rapidjson::Document json_doc;
        json_doc.Parse(payload_json.c_str());
        rapidjson::Value &op_code = json_doc["op"];
        return std::make_pair(op_code.GetInt(), std::move(json_doc));
    }

public:
    void process_event(const std::string &payload) {
        auto event_context = peek_opcode(payload);
        auto op_code = event_context.first;
        rapidjson::Document json_document = std::move(event_context.second);

        if (op_code == 10) {
            auto event_payload = deserialize<HelloGatewayEvent>(json_document);
            auto event_data = HelloEvent(event_payload);
            std::string name = "hello";
            auto event_message = EventMessage<HelloGatewayEvent>(name, event_payload);
            //todo: pass an event message that uses an enum as an identifier for the message type
            eventbus.post(event_payload);
        }
    }
};

#endif//WARFRAME_GATEWAY_EVENT_PROCESSOR_H
