//
// Created by Ariel Saldana on 5/30/23.
//

#ifndef WARFRAME_EVENTDATA_H
#define WARFRAME_EVENTDATA_H

#include <iostream>
#include <string>
#include <utility>
#include <any>

struct EventData {
    std::string * event_name;
    Payload<GatewayData> payload;

    explicit EventData(std::string * _event_name, Payload<GatewayData> _payload) {
//        event_name = std::move(_event_name);
        event_name = _event_name;
        payload = std::move(_payload);
    }

    [[nodiscard]] std::string get_event_name() const {
        return *event_name;
    }
};

#endif//WARFRAME_EVENTDATA_H
