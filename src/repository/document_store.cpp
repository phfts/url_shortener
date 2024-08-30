#pragma once

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/types.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/pool.hpp>
#include <mongocxx/uri.hpp>
#include <map>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

#include "./kv_store.hpp"

mongocxx::instance inst{};
mongocxx::pool pool = mongocxx::pool{mongocxx::uri{"mongodb://172.25.48.1:27017"}};

class DocumentStore : public KVStore
{
private:
    std::map<std::string, std::string> values;
    std::string db = "url_shortener_dev";
    std::string col = "main_collection";

    void setupIndex()
    {
        auto index_specification = make_document(kvp("hash", 1));
        auto conn = pool.acquire();
        auto collection = (*conn)[db][col];
        collection.create_index(std::move(index_specification));
    }

public:
    DocumentStore()
    {
        setupIndex();
    }

    bool has(std::string key)
    {
        auto conn = pool.acquire();
        auto collection = (*conn)[db][col];
        auto result = collection.count_documents(make_document(kvp("hash", key)));
        return result > 0;
    }

    std::string get(std::string key)
    {
        auto conn = pool.acquire();
        auto collection = (*conn)[db][col];
        auto result = collection.find_one(make_document(kvp("hash", key)));
        return result->view()["url"].get_string().value.to_string();
    }

    void set(std::string key, std::string value)
    {
        auto conn = pool.acquire();
        auto collection = (*conn)[db][col];
        auto result = collection.insert_one(make_document(kvp("hash", key), kvp("url", value)));
        if (!result)
        {
            throw std::runtime_error("Could not set key " + key);
        }
    }
};