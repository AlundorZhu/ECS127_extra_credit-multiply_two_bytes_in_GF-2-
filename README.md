# Multiply two bytes
```bash
prompt> make multiply_two_bytes_in_gf2
g++ -o multiply_two_bytes_in_gf2 multiply_two_bytes_in_gf2.cpp -Wall -Werror
prompt> ./multiply_two_bytes_in_gf2 10101111 00000011
11101010
```
## The choosen irreducible polynomial is g(x)
$` g(x) = x^8 + x^4 + x^3 + x + 1 `$

# Testing Multiplication in GF(2^8) forms a group
```bash
prompt>  % make test_gf2
g++ -o test_gf2 test_gf2.cpp -Wall -Werror -std=c++11
prompt> ./test_gf2 
Multiplication in GF(2^8) forms a group
```
