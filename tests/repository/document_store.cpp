#include <thread>

#include "../../src/repository/document_store.cpp"

TEST(DocumentStore, Concurrency)
{
    KVStore* store = new DocumentStore();
    std::string key = "123";
    std::string value = "4568";
    store->set(key, value);
    EXPECT_EQ(nullptr, store->get(key));
}