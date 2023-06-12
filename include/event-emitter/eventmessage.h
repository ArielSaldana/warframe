//
// Created by ariel on 6/1/23.
//

#ifndef WARFRAME_EVENTMESSAGE_H
#define WARFRAME_EVENTMESSAGE_H

#include <utility>

#include "gatewayevents/hello_gateway_event.h"
#include "gatewayevents/payload.h"


template<typename T>
struct EventMessage {
    std::string event_name;
    Payload<T> payload;
    EventMessage(std::string _event_name, Payload<T> &_payload)
        : event_name(std::move(_event_name)), payload(_payload) {
    }
};


#endif//WARFRAME_EVENTMESSAGE_H
