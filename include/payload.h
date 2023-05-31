//
// Created by Ariel Saldana on 5/29/23.
//

#ifndef WARFRAME_PAYLOAD_H
#define WARFRAME_PAYLOAD_H

#include <string>
template<typename T>
struct Payload {
    int op;       // Opcode
    T d;          // Payload event data
    int s;        // Sequence number
    std::string t;// EventData name
};

#endif//WARFRAME_PAYLOAD_H
