#pragma once 

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
        if (!kvStore->has(hash))
        {
            std::cout << "Could not find hash" << std::endl;
            return nullptr;
        }

        std::string value = kvStore->get(hash);
        std::cout << "Redirecting to " << value << std::endl;
        return value.c_str();
    }

    std::string saveUrl(std::string url)
    {
        std::string hash = generateBase62HashV2(7);
        while (kvStore->has(hash))
        {
            hash = generateBase62HashV2(7);
        }
        kvStore->set(hash, url);
        return hash;
    }
};