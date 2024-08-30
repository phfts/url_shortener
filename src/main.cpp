#define CROW_USE_BOOST 1

#include "crow.h"

#include "./controllers/urls_controller.cpp"

int main()
{
    crow::SimpleApp app;
    UrlsController* controller = UrlsController::factory();
    CROW_ROUTE(app, "/api/v1/").methods("POST"_method)([controller](const crow::request& req) { 
        return controller->create(req); 
    });
    CROW_ROUTE(app, "/<string>")([controller](const std::string& url) {
        return controller->get(url);
    });

    try
    {
        CROW_LOG_INFO << "Starting server";
        app.port(8080).multithreaded().run();
    }
    catch(const std::exception& e)
    {
        CROW_LOG_ERROR << "Error running server: " << e.what();
        return 1;
    }

    return 0;
}