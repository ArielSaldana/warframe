//
// Created by Ariel Saldana on 5/29/23.
//

#ifndef WARFRAME_ENCODER_H
#define WARFRAME_ENCODER_H

#pragma once

#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>
#include "erlpack/encoder.h"

class Encoder {
    static const size_t DEFAULT_RECURSE_LIMIT = 256;
    static const size_t INITIAL_BUFFER_SIZE = 1024 * 1024;

public:
    Encoder() {
        ret = 0;
        pk.buf = (char*)malloc(INITIAL_BUFFER_SIZE);
        pk.length = 0;
        pk.allocated_size = INITIAL_BUFFER_SIZE;

        ret = erlpack_append_version(&pk);
        if (ret == -1) {
            std::cout << "Unable to allocate large buffer for encoding." << std::endl;
        }
    }

    std::vector<uint8_t> releaseAsBuffer() {
        if (pk.buf == NULL) {
            return std::vector<uint8_t> {};
        }

        std::vector<uint8_t> buffer(pk.length);
        std::copy(pk.buf, pk.buf + pk.length, buffer.begin());
        pk.length = 0;
        erlpack_append_version(&pk);
        return buffer;
    }

    ~Encoder() {
        if (pk.buf) {
            free(pk.buf);
        }

        pk.buf = NULL;
        pk.length = 0;
        pk.allocated_size = 0;
    }

    template<typename T>
    int pack(const T& value, const int nestLimit = DEFAULT_RECURSE_LIMIT) {
        ret = 0;

        if (nestLimit < 0) {
            std::cout << "Reached recursion limit" << std::endl;
            return -1;
        }

        // Handle different value types using type traits or conditional statements
        if (std::is_integral<T>::value) {
            // Handle integral types
            // ...
        } else if (std::is_floating_point<T>::value) {
            // Handle floating-point types
            // ...
        } else if (std::is_same<T, std::string>::value) {
            // Handle std::string
            ret = erlpack_append_binary(&pk, value.c_str(), value.length());
        } else if (std::is_same<T, const char*>::value) {
            // Handle const char*
            // ...
        } else if (std::is_same<T, std::vector<T>>::value) {
            // Handle std::vector<T>
            // ...
        } else {
            // Handle other types
            // ...
        }

        return ret;
    }

private:
    int ret;
    erlpack_buffer pk;
};

#endif//WARFRAME_ENCODER_H
