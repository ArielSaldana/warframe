//
// Created by Ariel Saldana on 5/30/23.
//

#ifndef WARFRAME_EVENTEMITTER_H
#define WARFRAME_EVENTEMITTER_H

#include "eventdata.h"
#include <iostream>
#include <string>
#include <vector>

using EventHandler = std::function<void(EventData)>;

struct EventEmitter {
    std::string event_name;

//    std::vector<std::function<void()>> subscribers;
    std::vector<EventHandler> subscribers;
//    std::vector<std::function<void(Payload<ANY HERE>)>> subscribers;


//    template<typename func>
//    void on(func& lambda) {
//        subscribers.emplace_back(lambda);
//    }

//    template<typename func>
//    void on(func&& lambda) { // Now taking an rvalue reference
//        subscribers.emplace_back(std::forward<func>(lambda));
//    }

    template<typename func>
    void on(func lambda) { // Now taking by value
//        subscribers.emplace_back(std::move(lambda));
        // Convert the incoming function to our EventHandler type, and then store it
//        subscribers.emplace_back(static_cast<EventHandler>(std::move(lambda)));
        subscribers.emplace_back(EventHandler(lambda));
    }

    virtual void emit(EventData &event) {
//        if (event.event_name == "") {
//
//        }
        std::cout << "In Emit with subscriber coutn: " << subscribers.size() << std::endl;
        for (const auto& func : subscribers) {
            func(event); // Invoke the stored lambda function
        }
    }
};

#endif//WARFRAME_EVENTEMITTER_H
