//
// Created by Ariel Saldana on 5/29/23.
//

#ifndef WARFRAME_GATEWAY_H
#define WARFRAME_GATEWAY_H

#include "gateway_event_processor.h"
#include <iostream>
#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>

typedef websocketpp::client<websocketpp::config::asio_tls_client> client;
typedef websocketpp::lib::shared_ptr<websocketpp::lib::asio::ssl::context> context_ptr;
typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

class Gateway {

private:
    static context_ptr on_tls_init(const char *hostname, websocketpp::connection_hdl);
    static void on_message(client *c, websocketpp::connection_hdl hdl, message_ptr msg);

public:
    static void
    connect();
};

#endif//WARFRAME_GATEWAY_H
