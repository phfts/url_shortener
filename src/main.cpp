#define CROW_USE_BOOST 1

#include <string>
#include "crow.h"
#include "./controllers/urls_controller.cpp"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/api/v1/").methods("POST"_method)(UrlsController::create);
    CROW_ROUTE(app, "/api/v1/<string>")(UrlsController::get);

    app.port(8080).multithreaded().run();
}