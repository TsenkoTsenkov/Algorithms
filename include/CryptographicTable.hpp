struct Dictionary
{
    char key;
    char* value;
};

char* encrypt(char* input, Dictionary* dic, size_t dicSize);
size_t countEncryptionSymbols(const char* const input, const Dictionary*const dic, const size_t& size, const size_t& dicSize);
size_t countDecryptionSymbols(const char* const input, const Dictionary*const dic, const size_t& size, const size_t& dicSize);