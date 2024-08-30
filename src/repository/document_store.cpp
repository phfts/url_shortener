#pragma once

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/types.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/instance.hpp>
#include <map>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

#include "./kv_store.hpp"

class DocumentStore : public KVStore
{
private:
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{"mongodb://192.168.179.170:27017"}};
    std::map<std::string, std::string> values;

public:
    std::string *get(std::string key)
    {
        auto collection = conn["url_shortener_dev"]["main_collection"];
        auto result = collection.find_one(make_document(kvp("hash", key)));
        if (!result)
            return nullptr;
        std::string ret = result->view()["url"].get_string().value.to_string();
        values[key] = ret;
        return &values[key];
    }

    void set(std::string key, std::string value)
    {
        auto collection = conn["url_shortener_dev"]["main_collection"];
        auto result = collection.insert_one(make_document(kvp("hash", key), kvp("url", value)));
        if (!result)
        {
            throw std::runtime_error("Could not set key " + key);
        }
    }
};