//
// Created by GIGABYTE on 30.11.2022.
//

#include "header.hpp"

void decryption(const int& key, const std::string& file_name) {
    srand(key);
    std::ifstream file;
    file.open(file_name, std::ios::binary);
    std::vector<char> message((std::istreambuf_iterator<char>(file)),
                                    std::istreambuf_iterator<char>());
    file.close();
    std::string result;
    std::vector<unsigned char> bytes(message.size() * 2);
    for (unsigned int i = 0; i < message.size(); i += 2) {
        bytes[i] = message[i];
        bytes[i + 1] = i + 1 < message.size() ? message[i + 1] : 0u;
        unsigned int block;
        block = static_cast<unsigned int>(bytes[i]);
        block <<= 8u;
        block |= static_cast<unsigned int>(bytes[i + 1]);
        unsigned int gamma = rand() & 0xFFFF;
        block = block ^ gamma;
        block = block << 14u | block >> 2u;
        unsigned char sym1, sym2;
        sym1 = block >> 8u;
        result += sym1;
        sym2 = block;
        result += sym2;
    }
    std::cout << result;
}