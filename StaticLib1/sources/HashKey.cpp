#include <HashKey.h>

#define INVALID_HASH 0x00000000
#define HASH_INIT 0x811C9DC5
#define HASH_PRIME 0x01000193

thomas::HashKey::HashKey() :
    m_HashValue(INVALID_HASH)
{
}

thomas::HashKey::HashKey(const unsigned int aValue) :
    m_HashValue(aValue)
{
}

thomas::HashKey::HashKey(const char* aValue)
{
    m_HashValue = Generate(aValue);
}

thomas::HashKey::HashKey(const HashKey& aValue) :
    m_HashValue(aValue.m_HashValue)
{
}

void thomas::HashKey::Set(const unsigned int aValue)
{
    m_HashValue = aValue;
}

bool thomas::HashKey::Valid() const
{
    return (m_HashValue != INVALID_HASH);
}

unsigned int thomas::HashKey::Generate(const char* aValue)
{
    if (!aValue || !aValue[0])
    {
        return INVALID_HASH;
    }

    const unsigned char* tString = reinterpret_cast<const unsigned char*>(aValue);
    unsigned int tHash = HASH_INIT;

    while (*tString)
    {
        tHash *= HASH_PRIME;
        char tChar = *tString++;

        if (tChar == '\\')
        {
            tChar = '/';
        }

        if ((tChar >= 'a') && (tChar <= 'z'))
        {
            tChar -= 'a' - 'A';
        }

        tHash ^= static_cast<unsigned int>(tChar);
    }

    return tHash;
}
