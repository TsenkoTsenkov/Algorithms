#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../include/CryptographicTable.hpp"
#include <string.h>

TEST_CASE("ExampleTestCase", "[CryptographicTable]")
{
    constexpr int dicSize {8};
    Dictionary dic[dicSize] = 
    {
        {'i', "ala"},
        {'L', "bala"},
        {'d', "cana"},
        {'e', "h"},
        {'t', "disco"},
        {'o', "electro"},
        {'c', "pro"},
        {'a', "some"}
    };
    char* input = "I l0ve to code!";
    char* result = encrypt(input, dic, 8);

    REQUIRE(countEncryptionSymbols(input, dic, 15, 8) == 41);

    REQUIRE(strcmp(result, "ala bala0vh discoelectro proelectrocanah!") == 0);

    char* encrypted = "ala somem discoelectroelectro proelectroelectrobala!";
    REQUIRE(countDecryptionSymbols(encrypted, dic, strlen(encrypted), 8) == 14);

    delete[] result;
}