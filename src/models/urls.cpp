#include <string>
#include <iostream>

class Urls {
public:
    static const char* findByHash(std::string hash)
    {
        std::cout << "Looking for hash" << hash << std::endl;
        if (hash == "123") {
            std::cout << "Redirecting to google.com" << std::endl;
            return "http://www.google.com";
        }

        std::cout << "Could not find hash" << std::endl;
        return nullptr; 
    }
};