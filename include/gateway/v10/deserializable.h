//
// Created by Ariel Saldana on 6/12/23.
//

#ifndef WARFRAME_DESERIALIZABLE_H
#define WARFRAME_DESERIALIZABLE_H

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

template <typename T>
class Deserializable {
public:
    virtual T deserialize(const rapidjson::Value& json) = 0;
};

#endif //WARFRAME_DESERIALIZABLE_H
