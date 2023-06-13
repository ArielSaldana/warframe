//
// Created by Ariel Saldana on 6/12/23.
//

#ifndef WARFRAME_SERIALIZABLE_H
#define WARFRAME_SERIALIZABLE_H

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

class Serializable {
public:
    virtual rapidjson::Value serialize() = 0;
};

#endif //WARFRAME_SERIALIZABLE_H
