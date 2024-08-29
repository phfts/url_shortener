#define CROW_USE_BOOST 1

#include <string>
#include "crow.h"
#include "./src/models/urls.cpp"

// actions
// 1. shorten
// 2. get

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/api/v1/<string>")([](std::string hash){
        const char* url = Urls::findByHash(hash);
        if (url == nullptr)
        {
            return crow::response(404);
        }
        crow::response res(301);
        res.moved_perm(url);
        return res;
    });

    app.port(8080).multithreaded().run();
}