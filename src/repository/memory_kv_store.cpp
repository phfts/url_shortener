#pragma once

#include <map>
#include <mutex>

#include "./kv_store.hpp"

std::mutex mtx;

class MemoryKvStore : public KVStore {
private:
    std::map<std::string, std::string> store;

public:
    std::string* get(std::string key) 
    {
        if (store.count(key) == 0) 
            return nullptr;

        return &store[key];
    }

    void set(std::string key, std::string value) 
    {
        mtx.lock();
        store[key] = value;
        mtx.unlock();
    }    
};