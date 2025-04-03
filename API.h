#ifndef API_H
#define API_H

#include <string>
#include <curl/curl.h>

class API {
private:
    std::string app_id;
    std::string app_key;
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response);
    std::string urlEncode(const std::string& value) const;
    
public:
    API(const std::string& id, const std::string& key);
    ~API();
    std::string getNutritionData(const std::string& recipe) const;
};

#endif