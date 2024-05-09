CC=g++
CFLAGS=-Wall -Werror

all: multiply_two_bytes_in_gf2 test_gf2

multiply_two_bytes_in_gf2: multiply_two_bytes_in_gf2.cpp multiply_two_bytes_in_gf2.h
	$(CC) -o multiply_two_bytes_in_gf2 multiply_two_bytes_in_gf2.cpp $(CFLAGS)

test_gf2: test_gf2.cpp multiply_two_bytes_in_gf2.h
	$(CC) -o test_gf2 test_gf2.cpp $(CFLAGS) -std=c++11

clean:
	rm -f multiply_two_bytes_in_gf2 test_gf2