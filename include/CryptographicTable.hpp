struct Dictionary
{
    char key;
    char* value;
};

char* encrypt(char* input, const Dictionary* const dic, size_t dicSize);
int countEncryptionSymbols(const char* const input, const Dictionary*const dic, const size_t& size, const size_t& dicSize);
int countDecryptionSymbols(const char* const input, const Dictionary*const dic, const size_t& size, const size_t& dicSize);