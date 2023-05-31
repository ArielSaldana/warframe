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
    EventEmitter hello_event_emitter;
    /* Post an event to the event bus */
    template<typename T>
    void post(Payload<T> payload) {

        //        hello_event_emitter.on([&]() {
        //            std::cout << "from lambda" << std::endl;
        //            // your code here
        //        });\

        //        hello_event_emitter.on([]() {
        //
        //        });

        std::cout << "Attempting to register" << std::endl;
        std::function<void(EventData)> func = [](EventData data) {
            std::cout << "from here, data opcode: " <<  std::endl;
            // Your code here
        };

        hello_event_emitter.on(func);

        if (std::is_same<T, HelloGatewayEvent>::value) {
            std::cout << "from eventbus" << std::endl;
            HelloEvent he(&payload);
            hello_event_emitter.emit(he);
            //            hello_event_emitter.emit(he);
        }
    }

private:
    /* private function to verify event */
    void process_event();

    /* private function to route event */
    void route_event();
};

#endif//WARFRAME_EVENTBUS_H
