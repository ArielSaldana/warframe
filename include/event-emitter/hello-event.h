#include <utility>

//
// Created by Ariel Saldana on 5/30/23.
//

#ifndef WARFRAME_HELLO_EVENT_H
#define WARFRAME_HELLO_EVENT_H

#include "hello_gateway_event.h"
#include "payload.h"

struct HelloEvent : public EventData {
    std::string event_name = "hello_event_emitter";
    explicit HelloEvent(const Payload<HelloGatewayEvent>& payload) : EventData(HelloEvent::event_name, payload) {
    }
};

#endif//WARFRAME_HELLO_EVENT_H
