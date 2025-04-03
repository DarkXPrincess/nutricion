#include "API.h"
#include <iomanip>
#include <sstream>

API::API(const std::string& id, const std::string& key) : app_id(id), app_key(key) {}
API::~API() {}

size_t API::WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
    size_t totalSize = size * nmemb;
    response->append((char*)contents, totalSize);
    return totalSize;
}

std::string API::urlEncode(const std::string& value) const {
    std::ostringstream encoded;
    encoded << std::hex << std::uppercase;
    for (unsigned char c : value) {
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            encoded << c;
        } else {
            encoded << '%' << std::setw(2) << int(c);
        }
    }
    return encoded.str();
}

std::string API::getNutritionData(const std::string& recipe) const {
    CURL* curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if(curl) {
        std::string url = "https://api.edamam.com/api/nutrition-data?app_id=" + 
                         app_id + "&app_key=" + app_key + "&ingr=" + urlEncode(recipe);
        
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            throw std::runtime_error("Error en la solicitud: " + std::string(curl_easy_strerror(res)));
        }
        
        curl_easy_cleanup(curl);
    }
    return response;
}