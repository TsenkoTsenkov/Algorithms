#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../include/BitComparison.hpp"

TEST_CASE("ExampleTestCase", "[BitComparison]")
{
    int arraySize = 7;
    int* actual{new int[arraySize]{5, 8, 15, 11, 6, 1, 2}};

    binaryInsertionSort(actual, arraySize);

    int expected[7] = {15, 5, 11, 6, 1, 8, 2};
    for (int i=0; i<arraySize; i++){
        REQUIRE(actual[i] == expected[i]);
    }

    int expected2[5] = {15, 5, 11, 6, 1};
    int* newActual = deleteDuplicates(actual, arraySize);
    REQUIRE(arraySize == 5);
    for (int i=0; i<arraySize; i++)
    {
        REQUIRE(newActual[i] == expected2[i]);
    }
}

TEST_CASE("ExampleTestCase2", "[BitComparison]")
{
    int arraySize = 7;
    int* actual{new int[arraySize]{3, 3, 1, 2, 2, 2, 2}};

    binaryInsertionSort(actual, arraySize);

    int expected[7] = {3, 3, 1, 2, 2, 2, 2};
    for (int i=0; i<arraySize; i++){
        REQUIRE(actual[i] == expected[i]);
    }

    int expected2[1] = {1};
    int* newExpected = deleteDuplicates(actual, arraySize);
    REQUIRE(arraySize == 1);
    for (int i=0; i<arraySize; i++)
    {
        REQUIRE(newExpected[i] == expected2[i]);
    }
}

TEST_CASE("ExampleTestCase3", "[BitComparison]")
{
    int arraySize = 5;
    int* actual{new int[arraySize]{5, 5, 1, 5, 5}};

    binaryInsertionSort(actual, arraySize);

    int expected[5] = {5, 5, 5, 5, 1};
    for (int i=0; i<arraySize; i++){
        REQUIRE(actual[i] == expected[i]);
    }

    int expected2[1] = {1};
    int* newActual = deleteDuplicates(actual, arraySize);
    REQUIRE(arraySize == 1);
    for (int i=0; i<arraySize; i++)
    {
        REQUIRE(newActual[i] == expected2[i]);
    }
}

TEST_CASE("ExampleTestCase4", "[BitComparison]")
{
    int arraySize = 5;
    int* actual{new int[arraySize]{5, 5, 5, 5, 5}};

    binaryInsertionSort(actual, arraySize);

    int expected[5] = {5, 5, 5, 5, 5};
    for (int i=0; i<arraySize; i++){
        REQUIRE(actual[i] == expected[i]);
    }

    int* newActual = deleteDuplicates(actual, arraySize);
    REQUIRE(arraySize == 0);
}