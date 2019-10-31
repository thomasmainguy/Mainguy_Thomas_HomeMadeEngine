#ifndef THOMAS_HASH_KEY_H
#define THOMAS_HASH_KEY_H

namespace thomas
{
    class HashKey
    {
    public:
        HashKey();
        explicit HashKey(unsigned int aValue);
        explicit HashKey(const char* aValue);
        HashKey(const HashKey& aValue);

        void Set(unsigned int aValue);
        bool Valid() const;
        unsigned int GetHash() const { return m_HashValue; }

        static unsigned int Generate(const char* aValue);

    private:
        unsigned int m_HashValue{0};
    };
}

#endif
