#include <map>

#include "./kv_store.hpp"

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
        store[key] = value;
    }    
};