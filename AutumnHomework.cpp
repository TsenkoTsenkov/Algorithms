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

int countEvenBits(int a)
{
    return countBits(a, true);
}

static inline void toUnsigned(int &a)
{
    if (a < 0) {a = -a;}
}

int countOddBits(int a)
{
    return countBits(a, false);
}

bool compareBits(int a, int b, bool isEven)
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

bool compareWrapper(int a, int b)
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

int main()
{
    int arraySize;
    cin >> arraySize;
    if (arraySize < 0) {cout << "Negative value for array size error"; return -1;}

    int* arr = new(nothrow) int[arraySize];
    if (!arr) {cout << "Memory allocation error"; return -1;}

    for(int i=0; i<arraySize; ++i)
    {
        cin >> arr[i];
    }

    binaryInsertionSort(arr, arraySize);

    for(int i=0; i<arraySize; ++i)
    {
        cout << countEvenBits(arr[i]) + countOddBits(arr[i]) << ' ';
    }

    delete[] arr;
    return 0;
}