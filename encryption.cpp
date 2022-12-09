//
// Created by GIGABYTE on 23.11.2022.
//

#include "header.hpp"

void encryption(const std::string &message, const int &key, const std::string &file_name) {
    srand(key);
    std::vector<unsigned char> bytes(message.size() * 2);
    std::ofstream file;
    file.open(file_name, std::ios::binary);
    for (unsigned int i = 0; i < message.size(); i += 2) {
        bytes[i] = message[i];
        bytes[i + 1] = i + 1 < message.size() ? message[i + 1] : 0u;
        unsigned int block;
        block = static_cast<unsigned int>(bytes[i]);
        block <<= 8u;
        block |= static_cast<unsigned int>(bytes[i + 1]);
        block = block << 2 | block >> 14;
        unsigned int gamma = rand() & 0xFFFF;
        block = block ^ gamma;
        char sym1, sym2;
        sym1 = block >> 8u;
        sym2 = block;
        file.write(&sym1, sizeof(sym1));
        file.write(&sym2, sizeof(sym2));
    }
    file.close();
}
