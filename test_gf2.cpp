#include <iostream>
#include <cassert>
#include "multiply_two_bytes_in_gf2.h"

// Function to test if multiplication in GF(2^8) forms a group
bool test_gf_group() {
    // Verify closure
    for (int a = 0; a < 256; ++a) {
        for (int b = 0; b < 256; ++b) {
            unsigned char result = gf_multiply(static_cast<unsigned char>(a), static_cast<unsigned char>(b));
            if (result < 0 || result > 255) {
                std::cerr << "Failure of closure: " << a << " * " << b << " = " << static_cast<int>(result) << "\n";
                return false;
            }
        }
    }

    // Verify associativity
    for (int a = 1; a < 256; ++a) {
        for (int b = 1; b < 256; ++b) {
            for (int c = 1; c < 256; ++c) {
                if (gf_multiply(static_cast<unsigned char>(a), gf_multiply(static_cast<unsigned char>(b), static_cast<unsigned char>(c))) !=
                    gf_multiply(gf_multiply(static_cast<unsigned char>(a), static_cast<unsigned char>(b)), static_cast<unsigned char>(c))) {
                    std::cerr << "Failure of associativity: " << a << " * (" << b << " * " << c << ") != (" << a << " * " << b << ") * " << c << "\n";
                    return false;
                }
            }
        }
    }

    // Verify identity element
    unsigned char identity = 1;
    for (int a = 1; a < 256; ++a) {
        if (gf_multiply(static_cast<unsigned char>(a), identity) != a || gf_multiply(identity, static_cast<unsigned char>(a)) != a) {
            std::cerr << "Failure of identity: " << a << " * " << static_cast<int>(identity) << " != " << a << " or " << static_cast<int>(identity) << " * " << a << " != " << a << "\n";
            return false;
        }
    }

    // Verify inverse elements
    auto find_inverse = [](unsigned char x) -> unsigned char {
        for (int candidate = 1; candidate < 256; ++candidate) {
            if (gf_multiply(x, static_cast<unsigned char>(candidate)) == 1) {
                return static_cast<unsigned char>(candidate);
            }
        }
        return 0; // Indicating no inverse found
    };

    for (int a = 1; a < 256; ++a) {
        unsigned char inverse = find_inverse(static_cast<unsigned char>(a));
        if (inverse == 0 || gf_multiply(static_cast<unsigned char>(a), inverse) != 1 || gf_multiply(inverse, static_cast<unsigned char>(a)) != 1) {
            std::cerr << "Failure of inverse: No inverse for " << a << "\n";
            return false;
        }
    }

    std::cout << "Multiplication in GF(2^8) forms a group\n";
    return true;
}

int main() {
    assert(test_gf_group());
    return 0;
}
