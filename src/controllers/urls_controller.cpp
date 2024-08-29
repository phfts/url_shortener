#include "crow.h"
#include "../models/urls.cpp"

class UrlsController {
public:
    static crow::response get(std::string hash){
        const char* url = Urls::findByHash(hash);
        if (url == nullptr)
        {
            return crow::response(404);
        }
        crow::response res(301);
        res.moved_perm(url);
        return res;
    }

    static crow::response create(const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x || !x.has("url"))
            return crow::response(400, "{\"error\": \"url param is missing\"}");

        std::string url = x["url"].s();
        return crow::response(201, url);
    }
};