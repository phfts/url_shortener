#pragma once

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/types.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/instance.hpp>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_document;

#include "./kv_store.hpp"

class DocumentStore : public KVStore
{
private:
public:
    std::string *get(std::string key)
    {
        return nullptr;
    }

    void set(std::string key, std::string value)
    {
        // The mongocxx::instance constructor and destructor initialize and shut down the driver,
        // respectively. Therefore, a mongocxx::instance must be created before using the driver and
        // must remain alive for as long as the driver is in use.
        // mongocxx::instance inst{};
        // mongocxx::client conn{mongocxx::uri{"mongodb://localhost:27017"}};

        // try
        // {
        //     auto result = collection.insert_one(make_document(kvp("test", 1)));

        //     if (!result)
        //     {
        //         std::cout << "Unacknowledged write. No id available." << std::endl;
        //         return;
        //     }

        //     if (result->inserted_id().type() == bsoncxx::type::k_oid)
        //     {
        //         bsoncxx::oid id = result->inserted_id().get_oid().value;
        //         std::string id_str = id.to_string();
        //         std::cout << "Inserted id: " << id_str << std::endl;
        //     }
        //     else
        //     {
        //         std::cout << "Inserted id was not an OID type" << std::endl;
        //     }
        // }
        // catch (const mongocxx::exception &e)
        // {
        //     std::cout << "An exception occurred: " << e.what() << std::endl;
        //     return;
        // }

        // return;
    }
};