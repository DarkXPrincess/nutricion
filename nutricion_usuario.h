#ifndef NUTRITION_DISPLAYER_H
#define NUTRITION_DISPLAYER_H

#include <nlohmann/json.hpp>
#include <string>

class NutritionDisplayer {
public:
    static void display(const std::string& jsonResponse);
    static void displayCalories(const nlohmann::json& data);
};

#endif