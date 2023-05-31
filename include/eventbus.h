//
// Created by Ariel Saldana on 5/30/23.
//

#ifndef WARFRAME_EVENTBUS_H
#define WARFRAME_EVENTBUS_H

#include "event-emitter/eventdata.h"
#include "event-emitter/eventemitter.h"
#include "event-emitter/hello-event.h"
#include "hello_gateway_event.h"
#include "payload.h"
#include <iostream>
#include <vector>

class EventBus {
public:
    EventEmitter<HelloEvent> hello_event_emitter;
    /* Post an event to the event bus */
    template<typename T>
    void post(Payload<T> payload) {
        std::cout << "Attempting to register" << std::endl;
        std::function<void(HelloEvent)> func = [](const HelloEvent& data) {
            std::cout << "event_name in lambda: " << data.event_name << std::endl;
        };

        hello_event_emitter.on(func);

        if (std::is_same<T, HelloGatewayEvent>::value) {
            HelloEvent he(payload);
            std::cout << "event_name before emit: " << he.event_name << std::endl;
            hello_event_emitter.emit(he);
        }
    }

private:
    /* private function to verify event */
    void process_event();

    /* private function to route event */
    void route_event();
};

#endif//WARFRAME_EVENTBUS_H
