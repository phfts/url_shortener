#include <string>
#include <iostream>

#include "../repository/kv_store.hpp"
#include "../helpers/hash_helper.cpp"

class Urls
{
private:
    KVStore* kvStore;

public:
    Urls(KVStore* kvStore) : kvStore(kvStore) {}

    const char *findByHash(std::string hash)
    {
        std::cout << "Looking for hash " << hash << std::endl;
        std::string *value = kvStore->get(hash);
        if (value == nullptr)
        {
            std::cout << "Could not find hash" << std::endl;
            return nullptr;
        }

        std::cout << "Redirecting to " << *value << std::endl;
        return value->c_str();
    }

    std::string saveUrl(std::string url)
    {
        std::string hash = generateBase62Hash(7);
        kvStore->set(hash, url);
        return hash;
    }
};