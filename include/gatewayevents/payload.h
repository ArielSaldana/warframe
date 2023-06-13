//
// Created by Ariel Saldana on 5/29/23.
//

#ifndef WARFRAME_PAYLOAD_H
#define WARFRAME_PAYLOAD_H

#include "gatewayevents/serializable.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <string>
#include <type_traits>

template<typename T>
struct Payload : public Serializable {
    int op;       // Opcode
    T d;          // Payload event data
    int s;        // Sequence number
    std::string t;// EventData name

    std::string serialize() {
                rapidjson::Document document;
                document.SetObject();
                rapidjson::Value json(rapidjson::kObjectType);
                json.AddMember("op", op, document.GetAllocator());
//                json.AddMember("d", d, document.GetAllocator());  how do we get this working
                json.AddMember("device", rapidjson::Value(t.c_str(), document.GetAllocator()).Move(),
                                          document.GetAllocator());
        return "";
    }
};

#endif//WARFRAME_PAYLOAD_H
