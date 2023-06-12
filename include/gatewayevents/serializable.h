#ifndef WARFRAME_SERIALIZABLE_H
#define WARFRAME_SERIALIZABLE_H

#include <iostream>
#include <string>

class Serializable {
public:
    virtual std::string serialize() = 0;

//    virtual ~Serializable() = default;
};

#endif //WARFRAME_SERIALIZABLE_H
