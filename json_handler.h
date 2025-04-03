#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#include <string>

class JsonHandler {
public:
    static void saveToFile(const std::string& jsonResponse, const std::string& filename);
};

#endif