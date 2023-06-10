//
// Created by Ariel Saldana on 6/10/23.
//

#ifndef WARFRAME_IDENTIFY_GATEWAY_EVENT_H
#define WARFRAME_IDENTIFY_GATEWAY_EVENT_H

#include <iostream>
#include <string>

struct IdentityGatewayEventProperties {
    std::string os;
    std::string browser;
    std::string device;
};

struct IdentifyGatewayEvent {
    std::string token;
    int intents;
    IdentityGatewayEventProperties properties;
};

#endif //WARFRAME_IDENTIFY_GATEWAY_EVENT_H
