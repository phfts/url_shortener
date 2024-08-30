#define CROW_USE_BOOST 1

#include "crow.h"

#include "./controllers/urls_controller.cpp"
#include "./repository/document_store.cpp"

int main()
{
    crow::SimpleApp app;

    KVStore* store = new DocumentStore();
    Urls *urls = new Urls(store);
    auto controller = UrlsController(urls);

    CROW_ROUTE(app, "/api/v1/").methods("POST"_method)([&controller](const crow::request& req) { return controller.create(req); } );
    CROW_ROUTE(app, "/<string>")([&controller](std::string hash) { return controller.get(hash); } );

    try
    {
        CROW_LOG_INFO << "Starting server";
        app.port(8080).multithreaded().run();
    }
    catch(const std::exception& e)
    {
        CROW_LOG_ERROR << "Error running server" << e.what();
        return 1;
    }
    
    return 0;
}