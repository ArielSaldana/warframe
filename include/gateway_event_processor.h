//
// Created by Ariel Saldana on 5/30/23.
//

#ifndef WARFRAME_GATEWAY_EVENT_PROCESSOR_H
#define WARFRAME_GATEWAY_EVENT_PROCESSOR_H

//#include "event-emitter/eventmessage.h"
//#include "gatewayevents/hello_gateway_event.h"
//#include "gatewayevents/identify_gateway_event.h"
//#include "gatewayevents/payload.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "socket.h"
#include <eventbus.h>
#include <iostream>
#include <string>
#include <utility>
#include <websocketpp/client.hpp>
#include <websocketpp/config/asio_client.hpp>
#include "gateway/v10/payloads/payload.h"

typedef websocketpp::client<websocketpp::config::asio_tls_client> client;
typedef websocketpp::lib::shared_ptr<websocketpp::lib::asio::ssl::context> context_ptr;
typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

class GatewayEventProcessor {

//    EventBus eventbus;

//    template<typename T>
//    Payload<T> deserialize(const rapidjson::Document &json_doc) {
//        if (std::is_same<T, HelloGatewayEvent>::value) {
//            Payload<T> p;
//            p.op = json_doc["op"].GetInt();
//
//            auto data = json_doc["d"].GetObj();
//            HelloGatewayEvent hello{.heartbeat_interval = data["heartbeat_interval"].GetInt()};
//            p.d = hello;
//
//            return p;
//        }
//    }

    std::pair<int, rapidjson::Document> peek_opcode(const std::string &payload_json) {
        rapidjson::Document json_doc;
        json_doc.Parse(payload_json.c_str());
        rapidjson::Value &op_code = json_doc["op"];
        return std::make_pair(op_code.GetInt(), std::move(json_doc));
    }

public:
    void process_event(client *ws_client, websocketpp::connection_hdl hdl, const std::string &payload) {
        auto event_context = peek_opcode(payload);
        auto op_code = event_context.first;
        rapidjson::Document json_document = std::move(event_context.second);

        std::cout << "ATTEMPTING TO PROCESS EVENT" << std::endl;
        std::cout << op_code << std::endl;

        if (op_code == 10) {

            Payload::deserialize(json_document);
//            auto event_payload = deserialize<HelloGatewayEvent>(json_document);
//            auto event_data = HelloEvent(event_payload);
//            std::string name = "hello";
//            auto event_message = EventMessage<HelloGatewayEvent>(name, event_payload);
//            //todo: pass an event message that uses an enum as an identifier for the message type
//            eventbus.post(event_payload);
//
//            // send identify event
//            IdentifyGatewayEventProperties props;
//
//            props.browser = "warframe";
//            props.device = "warframe";
//            props.os = "linux";
//            std::string token = "";
//            IdentifyGatewayEvent ev(token, 512, props);
//
//            std::cout << ev.serialize() << std::endl;
//            websocketpp::lib::error_code ec;
//            ws_client->send(hdl, ev.serialize(), websocketpp::frame::opcode::text);
//            ws_client->send(std::move(hdl), ev, 2, ec);
            //    ws_client->send(hdl, msg->get_payload(), msg->get_opcode(), ec);
            //    if (ec) {
            //        std::cout << "Echo failed because: " << ec.message() << std::endl;
            //    }

        } else {

        }
    }
};

#endif//WARFRAME_GATEWAY_EVENT_PROCESSOR_H
