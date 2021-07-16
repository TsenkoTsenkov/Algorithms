#include <iostream>

using namespace std;

int countBits(int a, bool isEven)
{
    int count {0};
    int i,k {0};

    if (isEven)
    {
        i = 30; //MAX positive int
        k = 0;
    }
    else
    {
        i = 29;
        k = 1;
    }

    for (i; i>=k; i-=2)
    {
        if((a >> i) & 1)
        {
            ++count;
        }
    }
    return count;
}

static int countEvenBits(int a)
{
    return countBits(a, true);
}

static inline void toUnsigned(int &a)
{
    if (a < 0) {a = -a;}
}

static int countOddBits(int a)
{
    return countBits(a, false);
}

static int compareBits(int a, int b, bool isEven)
{
    toUnsigned(a);
    toUnsigned(b);

    int resA;
    int resB;

    if(isEven)
    {
        resA = countEvenBits(a);
        resB = countEvenBits(b);
    }
    else
    {
        resA = countOddBits(a);
        resB = countOddBits(b);
    }

    if(resA < resB)
    {
        return 0;
    }
    if(resA > resB)
    {
        return 1;
    }
    else
    {
        if(isEven)
        {
            return compareBits(a, b, false);
        }
        else
        {
            return -1;
        }
    }
}

static int compareWrapper(int a, int b)
{
    return compareBits(a, b, true);
}

void binaryInsertionSort(int* arr, int arraySize)
{
    int x, med, r, l, j {0};
    for (int i = 1; i<arraySize; ++i)
    {
        x = arr[i];
        l = 0;
        r = i - 1;

        while (l <= r)
        {
            med = l + (r - l) / 2;
            if (!compareWrapper(arr[med], x))
            {
                r = med - 1;
            }
            else
            {
                l = med + 1;
            }
        }

        for (j = i - 1; j >= l; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[l] = x;
    }
}

static void deleteElement(int * arr, int& size, int pos)
{
    --size;
    for (int i=pos; i<size; ++i)
    {
        arr[i] = arr[i+1];
    }
}

void deleteDuplicates(int* arr, int& arraySize)
{
    for (int i=0; i<arraySize-1; ++i)
    {
        if (compareWrapper(arr[i], arr[i+1]) == -1)
        {
            while (compareWrapper(arr[i], arr[i+1]) == -1 && (i < arraySize-1))
            {
                deleteElement(arr, arraySize, i);
            }
            deleteElement(arr, arraySize, i);
        }
    }
}