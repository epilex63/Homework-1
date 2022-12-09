//
// Created by GIGABYTE on 23.11.2022.
//

#include "header.hpp"

// Первый параметр - encryption/decryption
// Второй параметр - путь к файлу
// Третий параметр - ключ
// Четвёртый параметр - сообщение
int main(int argc, const char *argv[]) {
    if (argc != 5) {
        std::cerr << "Error: Use four parameters\n";
        return 1;
    }
    const std::string mode = argv[1];
    const std::string file_name = argv[2];
    const int key = atoi(argv[3]);
    if (mode == "encryption") {
        const std::string message = argv[4];
        encryption(message, key, file_name);
    } else {
        if (mode == "decryption") {
            decryption(key, file_name);
        }
    }
    return 0;
}