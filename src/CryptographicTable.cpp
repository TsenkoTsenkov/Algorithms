#include <iostream>

using std::cin;
using std::cout;
using std::nothrow;

struct Dictionary
{
    char key;
    char* value;
};

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
        return p - 'a' + 'A';
    else {return p;}
}

int countEncryptionSymbols(const char* const input, const Dictionary*const dic, const size_t& size, const size_t& dicSize)
{
    int count{0};
    bool isKey{false};
    for (size_t i=0; i<size; ++i)
    {
        isKey = false;
        for(size_t j=0; j<dicSize; ++j)
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

// Check if a letter is part of a word
bool isWordLetter(char c)
{
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z');
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

char* encrypt(char* input, const Dictionary*const dic, size_t dicSize)
{
    size_t inputSize {strlen(input)};
    int resultSize{countEncryptionSymbols(input, dic, inputSize, dicSize)};
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

// Counts the words in a text.
int wordCount(const char* text)
{
    int cnt = 0;
    while (*text) {
        while (*text && !isWordLetter(*text)) {  // skip letters to the beginning of a word
            ++text;
        }
        if (*text) {
            ++cnt;                              // if there is a word, count it
        }
        while (isWordLetter(*text)) {           // skip to the end of the word
            ++text;
        }
    }
    return cnt;
}

//cpy paste form lecture 10
// Check if a string is part of another string.
// Return a pointer to the first occurrence or NULL
// A naive algorithm.
const char* strstr(const char* where, const char* what, size_t& lastIndex)
{
    size_t whatLen = strlen(what);
    size_t whereLen = strlen(where);
    size_t pos;
    const char* whereEnd = where + whereLen;
    lastIndex = 0;
    while (where+whatLen <= whereEnd) {
        for (pos = 0; pos < whatLen; ++pos) {
            if (where[pos] != what[pos]) {
                lastIndex -= pos;
                break;
            }
            ++lastIndex;
        }
        if (!what[pos])
        { 
            return where;
        }
        ++lastIndex;
        ++where;
    }
    return nullptr;
}

//Cpy/paste from L10 examples
/**********************************************************/
// Extract all the words from a text in a new array
// Allocates memory for that array and for each word
// Returns the count of extracted words
int extractWords(const char* text, char *** wordsPtr)
{
    int cnt = wordCount(text);  // found the count of the words
    *wordsPtr = new(nothrow) char*[cnt];    // allocate memory for the index array
    if (!*wordsPtr) return 0;

    for (int i = 0; i < cnt; ++i){          // for each word
        // go to the beginning of the word
        while (*text && !isWordLetter(*text))
            ++text;
        if (*text) {     // and if there is any
            const char* start = text;
            while (isWordLetter(*text))     // go to the end
                ++text;

            int len = text - start;         // and calculate the length of that word
            (*wordsPtr)[i] = new(nothrow) char[len+1];      // allocate memory for the word
            if (!(*wordsPtr)[i]) {    // If the allocation fails
                // cout << "No memory for word " << i;
                // return i;             // Return the number of successfully allocated words
                // Alternative approach - clear all the memory
                for (--i; i >= 0; --i)
                    delete[](*wordsPtr)[i];
                delete[] (*wordsPtr);
                *wordsPtr = NULL;
                return 0;
            }
            for (int pos = 0; pos < len; ++pos)             // copy the word
                (*wordsPtr)[i][pos] = start[pos];
            (*wordsPtr)[i][len] = '\0';                     // put a terminal symbol at the end
        }
    }
    return cnt;
}

char* strncpy(char * dst, const char * src, size_t num)
{
   while (num-- && (*dst++ = *src++))
    ;
    return dst - num;
}

//copies the last n characters of source into destination;
char* strlcpy(char * dst, const char * src, size_t num)
{
    while (*src++)
        ;
    src -= num + 1;
    while (*dst++ = *src++)
        ;
    return dst - num;
}

typedef char* (*strFun)(char*, const char*, size_t);
void operateWithString(const char* word, const Dictionary*const dic, const size_t& dicSize, size_t& count,size_t charsCount, strFun fun);

void longestSubstringValue(const char* const word, const Dictionary*const dic, const size_t& dicSize, size_t& count, size_t wordSize)
{
    int max{0};
    bool hasBeen{false};

    const char* tmpLastOccur{nullptr};
    const char* tmpFirstOccur{nullptr};
    const char* firstOccur{nullptr};
    const char* lastOccur{nullptr};

    int diff{0};
    size_t lastOccurIndex = 0;

    if(word)
    {
        for (size_t i=0; i<dicSize; ++i)
        {
            tmpFirstOccur = strstr(word, dic[i].value, lastOccurIndex);
            if(tmpFirstOccur)
            {
                tmpLastOccur = &word[lastOccurIndex];
                diff = tmpLastOccur - tmpFirstOccur;
                if(!max)
                {
                    hasBeen = true;
                    max = diff;
                    firstOccur = tmpFirstOccur;
                    lastOccur = tmpLastOccur;
                }
                else
                {
                    if (max < diff)
                    {
                        max = diff;
                        lastOccur = tmpLastOccur;
                        firstOccur = tmpFirstOccur;
                    }
                }
            }
        }
    } else {return;}

    if(!hasBeen)
    {
        count += strlen(word);
        return;
    }
    ++count;

    size_t charsCount = firstOccur - word;
    if(charsCount > 0)
        operateWithString(word, dic, dicSize, count, charsCount, strncpy);

    charsCount = &word[wordSize] - lastOccur;
    if(charsCount > 0)
        operateWithString(word, dic, dicSize, count, charsCount, strlcpy);
}

void operateWithString(const char* word, const Dictionary*const dic, const size_t& dicSize, size_t& count,size_t charsCount, strFun fun)
{
    char *newString = new(nothrow) char[charsCount + 1];
    if(!newString) {cout << "Memory allocation error!";return;}

    fun(newString, word, charsCount);
    newString[charsCount] = '\0';
    longestSubstringValue(newString, dic, dicSize, count, charsCount);

    delete[] newString;
}

//longest dictionary value
size_t countDecryptionSymbols(const char* const input, const Dictionary*const dic, const size_t& size, const size_t& dicSize)
{
    char** words;
    int resWords{extractWords(input, &words)};
    if(!resWords) {return 0;}

    size_t count{0};
    int wordsCounter{0};

    size_t i{0};
    while(i < size)
    {
        while (i<size && !isWordLetter(input[i])) { 
            ++count;
            ++i;
        }
        if (i == size){break;}
        longestSubstringValue(words[wordsCounter], dic, dicSize, count, strlen(words[wordsCounter]));
        i+=strlen(words[wordsCounter++]);
    }

    for (int i=0; i<resWords; i++)
    {
        delete[] words[i];
    }
    delete[] words;

    return count;
}

void printArr(char arr[], size_t size)
{
    for (size_t i=0; i<size; ++i)
    {
        cout << arr[i];
    }
}

void longestDecrypt(const char* const word, char* result, const Dictionary*const dic, const size_t& dicSize, size_t wordSize)
{
    int max{0};
    bool hasBeen{false};

    const char* tmpLastOccur{nullptr};
    const char* tmpFirstOccur{nullptr};
    const char* firstOccur{nullptr};
    const char* lastOccur{nullptr};

    int diff{0};
    size_t lastOccurIndex = 0;

    if(word)
    {
        for (size_t i=0; i<dicSize; ++i)
        {
            tmpFirstOccur = strstr(word, dic[i].value, lastOccurIndex);
            if(tmpFirstOccur)
            {
                tmpLastOccur = &word[lastOccurIndex];
                diff = tmpLastOccur - tmpFirstOccur;
                if(!max)
                {
                    hasBeen = true;
                    max = diff;
                    firstOccur = tmpFirstOccur;
                    lastOccur = tmpLastOccur;
                }
                else
                {
                    if (max < diff)
                    {
                        max = diff;
                        lastOccur = tmpLastOccur;
                        firstOccur = tmpFirstOccur;
                    }
                }
            }
        }
    } else {return;}

    if(!hasBeen)
    {
       // count += strlen(word);
        return;
    }
    //++count;

}

char* decrypt(char* input, Dictionary* dic, size_t dicSize)
{
    size_t size {strlen(input)};
    size_t resultSize{countDecryptionSymbols(input, dic, size, dicSize)};
    

    char* decrypted = new(nothrow) char[resultSize+1];
    if (!decrypted) {cout << "Memory allocation error!"; return nullptr;}

    char** words;
    int resWords{extractWords(input, &words)};
    if(!resWords) {delete[] decrypted; return nullptr;}

    int wordsCounter{0};
    size_t i{0};
    while(i < size)
    {
        while (i < size && !isWordLetter(input[i]))
        {
            decrypted[i] = input[i];
            ++i;
        }
        if (i == size){break;}
        longestDecrypt(words[wordsCounter], decrypted, dic, dicSize, strlen(words[wordsCounter]));
    }

    return decrypted;
}