#pragma once

#include <map>
#include <mutex>

#include "./kv_store.hpp"

class MemoryKvStore : public KVStore
{
private:
    std::mutex mtx;
    std::map<std::string, std::string> store;

public:
    bool has(std::string key)
    {
        return (store.count(key) != 0);
    }
    
    std::string get(std::string key)
    {
        return store[key];
    }

    void set(std::string key, std::string value)
    {
        mtx.lock();
        store[key] = value;
        mtx.unlock();
    }
};