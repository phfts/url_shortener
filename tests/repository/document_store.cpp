#include <thread>

#include "../../src/repository/document_store.cpp"

TEST(DocumentStore, SimpleUse)
{
    KVStore *store = new DocumentStore();
    std::string key = "123";
    std::string value = "4568";
    store->set(key, value);
    EXPECT_EQ(value, store->get(key));
}

TEST(DocumentStore, Performance)
{
    KVStore *store = new DocumentStore();
    for (int i = 1; i <= 1e4; i++)
    {
        std::string key = "k_" + std::to_string(i);
        std::string value = "v_" + std::to_string(i);
        store->set(key, value);

        if (i > 2)
            store->get("k_" + std::to_string(i-2));
    }
}