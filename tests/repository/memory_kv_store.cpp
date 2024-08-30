#include <thread>

#include "../../src/repository/memory_kv_store.cpp"
#include "../../src/repository/document_store.cpp"
#include "../../src/models/urls.cpp"

void setting(Urls *urls)
{
    for (int i=0; i<100000; i++)
    {
        urls->saveUrl("http://www.google.com");
    }
}


TEST(MemoryKvStore, Concurrency)
{
    KVStore* store = new MemoryKvStore();
    Urls *urls = new Urls(store);

    thread t1([&urls]() { setting(urls); });
    thread t2([&urls]() { setting(urls); });
    t1.join();
    t2.join();
}

TEST(DocumentStore, Concurrency)
{
    KVStore* store = new DocumentStore();
    Urls *urls = new Urls(store);

    thread t1([&urls]() { setting(urls); });
    thread t2([&urls]() { setting(urls); });
    t1.join();
    t2.join();
}