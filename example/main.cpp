//
// Created by Ariel Saldana on 5/29/23.
//

#include "decoder.h"
#include "encoder.h"
#include "gateway.h"
#include "library.h"
#include <iostream>
#include <string>

std::string vector_to_hex_string(const std::vector<uint8_t> &vec) {
    std::stringstream ss;

    for (const auto &element: vec) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(element);
    }

    return ss.str();
}

std::string vector_to_string(const std::vector<uint8_t> &vec) {
    std::string result(vec.begin(), vec.end());
    return result;
}

int main() {
    //    Encoder encoder;
    //
    //    std::string str = "ni hao woshi";
    //    int result = encoder.pack<std::string>(str);
    //
    //
    //    if (result > 0) {
    //        std::cout << "Unknown error" << std::endl;
    //    } else if (result == -1) {
    //        std::cout << "Out of memory" << std::endl;
    //    }
    //
    //    auto value = encoder.releaseAsBuffer();
    //    std::cout << vector_to_string(value) << std::endl;
    //
    //    std::cout << "Done" << std::endl;
    //
    //    Decoder decoder(value);
    //    auto decoded = decoder.unpack<std::string>();
    //    std::cout << decoded << std::endl;
    Gateway gateway;
    gateway.connect();
//    Gateway::connect();
    return 0;
}
