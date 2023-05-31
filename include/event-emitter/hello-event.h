#include <utility>

//
// Created by Ariel Saldana on 5/30/23.
//

#ifndef WARFRAME_HELLO_EVENT_H
#define WARFRAME_HELLO_EVENT_H

struct HelloEvent : public EventData {
    std::string event_name = "hello_event_emitter";
    explicit HelloEvent(std::any payload) : EventData(event_name, std::move(payload)) {

    }
};

#endif//WARFRAME_HELLO_EVENT_H
