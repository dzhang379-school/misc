#include <iostream>
#include "./picosha2.h"
#include <stdlib.h>
#include <cstring>
#include <ctime>

int main(int argc, char* argv[])
{
    std::string pub_key = "0400d011d46d61958d83fe30a0329e3e7f2812c2b168a1203525242813b45a348f0d32d24ad2a521115067fa39218c34ae759bf6cf0bb4e8205e0d8893cc2e566a94ef01a6c098eeefdbd6d9f7bf2b6982fd76394d01109c7f5184ad61efda1bc78d8c1d734ad9345a764b7f9ae2bb2039993518c617b3cdcc676d5e2e00d1c1f820c7fdcc";
    std::string username = "grahamgrahamgrahamgrahamgrahamgraham";
    std::string str = "$" + username + pub_key;

    int i;
    int nonce = 905689;
    char buffer1[16];
    std::string input;
    std::string hash;
    std::string min = "00001d04def655ca402e7ac0531a13a70d384bf3a8976ba34208e3422d6ba9aa";

    //clock_t begin = clock();
    for(long int j = 0; j < 1e19; ++j) {

        itoa(nonce, buffer1, 16);
        input = str + buffer1;
        picosha2::hash256_hex_string(input, hash);

        i = 0;
        while(hash[i] == min[i]) {
            ++i;
        }

        if (hash[i] < min[i]){
            min = hash;
            std::cout << min << ", " << nonce << std::endl;
        }

        ++nonce;
    }
}