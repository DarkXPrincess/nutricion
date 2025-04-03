#include "nutricion_usuario.h"
#include <iostream>

void NutritionDisplayer::displayCalories(const nlohmann::json& data) {
    if (data.contains("calories")) {
        std::cout << "\nCalorías totales para esta receta: " << data["calories"] << " kcal\n";
    }
}

void NutritionDisplayer::display(const std::string& jsonResponse) {
    auto data = nlohmann::json::parse(jsonResponse);
    displayCalories(data);
}