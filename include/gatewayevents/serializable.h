#ifndef WARFRAME_SERIALIZABLE_H
#define WARFRAME_SERIALIZABLE_H

#include <iostream>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

class Serializable {
public:
    virtual std::string serialize() = 0;

//    virtual ~Serializable() = default;
};

#endif //WARFRAME_SERIALIZABLE_H
