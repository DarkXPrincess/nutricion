#include "json_handler.h"
#include <fstream>

void JsonHandler::saveToFile(const std::string& jsonResponse, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << jsonResponse;
        file.close();
    } else {
        throw std::runtime_error("No se pudo abrir el archivo para escritura");
    }
}