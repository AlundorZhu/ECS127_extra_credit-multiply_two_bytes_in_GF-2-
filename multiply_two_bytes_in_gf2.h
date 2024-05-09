#ifndef _MULTIPLY_TWO_BYTES_IN_GF2_H_
#define _MULTIPLY_TWO_BYTES_IN_GF2_H_

/* 
    Multiply two bytes in GF(2)
    The choosen irreducible polynomial is g(x)
    g(x) = x^8 + x^4 + x^3 + x + 1
*/

void multiply_x(unsigned char& byte) {
    // check if the most significant bit is 1
    if (byte & 0x80) {
        // shift left by 1 and xor with 0x1B
        byte = (byte << 1) ^ 0x1B;
    } else {
        // shift left by 1
        byte = byte << 1;
    }
}

unsigned char gf_multiply(unsigned char byte1, unsigned char byte2) {

    // multiply the bytes
    unsigned char result = 0;
    for (int i = 0; i < 8; i++) {
        if (byte2 & 0x01) {
            result ^= byte1; // add in GF(2)
        }
        multiply_x(byte1);
        byte2 = byte2 >> 1;
    }
    
    return result;
}

#endif // _MULTIPLY_TWO_BYTES_IN_GF2_H_