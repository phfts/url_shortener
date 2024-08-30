#include <string>
#include "crow.h"

#include "../models/urls.cpp"
#include "../repository/document_store.cpp"

class UrlsController {
private:
    Urls* urls;

public:
    UrlsController(Urls* urls) : urls(urls) {}

    static UrlsController* factory()
    {
        KVStore* store = new DocumentStore();
        Urls *urls = new Urls(store);
        return new UrlsController(urls);
    }

    crow::response get(std::string hash){
        const char* url = urls->findByHash(hash);
        if (url == nullptr)
            return crow::response(404);

        crow::response res(301);
        res.moved_perm(url);
        return res;
    }

    crow::response create(const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x || !x.has("url"))
            return crow::response(400, "{\"error\": \"url param is missing\"}");

        std::string url = urls->saveUrl(x["url"].s());
        crow::json::wvalue res = {{"url", url}};
        return crow::response(201, res);
    }
};