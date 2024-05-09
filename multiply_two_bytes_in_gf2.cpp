# include <iostream>
# include "multiply_two_bytes_in_gf2.h"

void printBinary(unsigned char byte) {
    for (int i = 7; i >= 0; i--) {
        std::cout << ((byte >> i) & 1); // Shift and mask each bit to print
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    // help message
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <byte1> <byte2>" << std::endl;
        return 1;
    }

    // get the input bytes
    unsigned char byte1 = std::stoi(argv[1], nullptr, 2);
    unsigned char byte2 = std::stoi(argv[2], nullptr, 2);

    // multiply the bytes
    unsigned char result = gf_multiply(byte1, byte2);
    printBinary(result);
}