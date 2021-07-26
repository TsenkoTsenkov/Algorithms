#include <iostream>

using std::cin;
using std::cout;
using std::nothrow;

struct Dictionary
{
    char key;
    char* value;
};

//char* encrypt(char* input, const Dictionary*const dic);

// int main()
// {
//     return 0;
// }

size_t strlen(const char* text)
{
    size_t len = 0;
    while (text[len])
        ++len;
    return len;
}

char toUpper(char p)
{
    if(p >= 'a' && p <= 'z')
        p -= 32;
    return p;
}

size_t countEncryptionSymbols(const char* const input, const Dictionary*const dic, const size_t& size, const size_t& dicSize)
{
    size_t count{0};
    bool isKey{false};
    for (int i=0; i<size; ++i)
    {
        isKey = false;
        for(int j=0; j<dicSize; ++j)
        {
            if (toUpper(dic[j].key) == toUpper(input[i]))
            {
                count += strlen(dic[j].value);
                isKey = true;
                break;
            }
        }
        if(!isKey) {++count;}
    }
    return count;
}

char * strcat(char *dest, const char *src)
{
    size_t i,j;
    for (i = 0; dest[i] != '\0'; i++)
        ;
    for (j = 0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    return dest;
}

char* encrypt(char* input, Dictionary* dic, size_t dicSize)
{
    size_t inputSize {strlen(input)};
    size_t resultSize{countEncryptionSymbols(input, dic, inputSize, dicSize)};
    if (inputSize == resultSize) {return nullptr;}

    char* encrypted = new(nothrow) char[resultSize+1];
    if (!encrypted) {cout << "Memory allocation error!"; return nullptr;}
    encrypted[0] = '\0';
    
    bool isKey{false};
    size_t k{0};
    for (size_t i=0; i<inputSize; ++i)
    {
        isKey = false;
        for(size_t j=0; j<dicSize; ++j)
        {
            if (toUpper(dic[j].key) == toUpper(input[i]))
            {
                encrypted = strcat(encrypted, dic[j].value);
                isKey = true;
                k+=strlen(dic[j].value);
                break;
            }
        }
        if(!isKey)
        {
            encrypted[k] = input[i];
            k++;
        }
        encrypted[k] = '\0';
    }
    return encrypted;
}