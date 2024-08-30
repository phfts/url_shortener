#pragma once 

#include <string>
#include <iostream>

#include "../repository/kv_store.hpp"
#include "../helpers/hash_helper.cpp"

class Urls
{
private:
    KVStore* kvStore;
    
    std::string trySaveUrl(std::string url, int count = 0)
    {
        try
        {
            std::string hash = generateBase62HashV2(7);
            kvStore->set(hash, url);
            return hash;
        }
        catch(const std::exception& e)
        {
            return "";
        }
    }

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
        std::string hash = "";
        for (int i=0; i<5;i++)
        {
            hash = trySaveUrl(url, i);
            if (hash != "") break;
        }
        if (hash == "") {
            throw std::runtime_error("Error saving url after max retries. Url was " + url);
        }
        return hash;
    }
};