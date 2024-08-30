#include "../../src/controllers/urls_controller.cpp"
#include "../../src/repository/memory_kv_store.cpp"

TEST(UrlsController, createInvalid)
{
    crow::request req;
    req.body = "{}";
    KVStore *store = new MemoryKvStore();
    Urls *urls = new Urls(store);
    auto controller = UrlsController(urls);
    crow::response res = controller.create(req);
    EXPECT_EQ(400, res.code);
}

TEST(UrlsController, createValid)
{
    crow::request req;
    req.body = "{\"url\": \"http://www.google.com\"}";
    KVStore* store = new MemoryKvStore();
    Urls *urls = new Urls(store);
    auto controller = UrlsController(urls);
    crow::response res = controller.create(req);
    EXPECT_EQ(201, res.code);

    auto x = crow::json::load(res.body);
    EXPECT_EQ(7, x["url"].size());
}

TEST(UrlsController, getFound)
{
    crow::request req;
    req.body = "{\"url\": \"http://www.google.com\"}";
    KVStore* store = new MemoryKvStore();
    Urls *urls = new Urls(store);
    auto controller = UrlsController(urls);
    crow::response res = controller.create(req);

    auto x = crow::json::load(res.body);
    auto newUrl = x["url"].s();

    res = controller.get(newUrl);
    EXPECT_EQ(301, res.code);
}

TEST(UrlsController, getNotFound)
{
    KVStore* store = new MemoryKvStore();
    Urls *urls = new Urls(store);
    auto controller = UrlsController(urls);
    crow::response res = controller.get("1234");
    EXPECT_EQ(404, res.code);
}
