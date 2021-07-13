#include <iostream>

using namespace std;

int countBits(int a, bool isEven)
{
    int count {0};
    int i,k {0};

    isEven ? i=30,k=0 : i=29,k=1;

    for (i; i>=k; i-=2)
    {
        if((a >> i) & 1)
        {
            cout << '1';
            ++count;
        } else { cout << '0';}
    }
    return count;
}

int countEvenBits(int a)
{
    return countBits(a, true);
}

int countOddBits(int a)
{
    return countBits(a, false);
}

bool compareBits(int a, int b, bool isEven)
{
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
        return true;
    }
    if(resA > resB)
    {
        return false;
    }
    else
    {
        if(isEven)
        {
            return compareBits(a, b, false);
        }
        else
        {
            return false;
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
            if (compareWrapper(arr[med], x))
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
    // cin >> arraySize;
    // if (arraySize < 0) {cout << "Negative value for array size error"; return -1;}

    // int* arr = new(nothrow) int[arraySize];
    // if (!arr) {cout << "Memory allocation error"; return -1;}


    // for(int i=0; i<arraySize; ++i)
    // {
    //     cin >> arr[i];
    // }

    //InsertionSort(arr, arraySize);

    // for(int i=0; i<arraySize; ++i)
    // {
    //     cout << countBits(arr[i], true) << ' ' ;
    // }
    //cout << endl;
    cout << countBits(50, true);

    //delete[] arr;
    return 0;
}