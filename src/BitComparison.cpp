#include <iostream>

using std::cin;
using std::cout;
using std::nothrow;

void binaryInsertionSort(int*const arr, const int& arraySize);
void printArr(const int*const arr, const int& arraySize);
int* deleteDuplicates(int*const arr, int& arraySize);

// int main()
// {
//     int arraySize;
//     cin >> arraySize;
//     if (arraySize < 0) {cout << "Negative value for array size error"; return -1;}
    
//     int* arr = new(nothrow) int[arraySize];
//     if (!arr) {cout << "Memory allocation error"; return -1;}

//     for(int i=0; i<arraySize; ++i)
//     {
//         cin >> arr[i];
//     }

//     binaryInsertionSort(arr, arraySize);
//     printArr(arr, arraySize);

//     int* filteredArr = deleteDuplicates(arr, arraySize);
//     if (!filteredArr) {return -1;}

//     if (arraySize != 0)
//     {
//         cout << '\n';
//         printArr(filteredArr, arraySize);
//     }

//     delete[] filteredArr;

//     return 0;
// }

int countBits(const int& a, const bool& isEven)
{
    int count {0};
    int i,k {0};
    constexpr int maxPosIntBit {30};

    if (isEven)
    {
        i = maxPosIntBit;
        k = 0;
    }
    else
    {
        i = maxPosIntBit - 1;
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

int countEvenBits(const int& a)
{
    return countBits(a, true);
}

inline void toUnsigned(int &a)
{
    if (a < 0) {a = -a;}
}

int countOddBits(const int& a)
{
    return countBits(a, false);
}

int compareBits(int& a, int& b, const bool& isEven)
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

int compareWrapper(int a, int b)
{
    return compareBits(a, b, true);
}

void binaryInsertionSort(int *const arr, const int& arraySize)
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

void deleteElement(int*const arr, int& size, const int& pos)
{
    --size;
    for (int i=pos; i<size; ++i)
    {
        arr[i] = arr[i+1];
    }
}

int* deleteDuplicates(int*const arr, int& arraySize)
{
    int sizeCppy{arraySize};
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
    if (sizeCppy == arraySize) {return arr;}

    int* newArr = new(nothrow) int[arraySize];
    if (!newArr) {cout << "Memory allocation error!"; delete[] arr; return nullptr;}

    for (int i=0; i<arraySize; ++i)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    return newArr;
}

void printArr(const int* const arr, const int& size)
{
    for (int i=0; i<size; ++i)
    {
        cout << arr[i] << ' ';
    }
}