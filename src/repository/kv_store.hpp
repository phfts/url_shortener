#pragma once
#include <string>

class KVStore {
public:
    virtual std::string* get(std::string) = 0;
    virtual void set(std::string, std::string) = 0;
};