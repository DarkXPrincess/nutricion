/*
    Proyecto: Nutricion
    Curso: Fundamentos de Programaci�n Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripci�n:
    Este proyecto permite trabajar con:
    Uso de clases
    Uso de bibliotecas
    Uso de APIs
    Reutilizaci�n de c�digo
    Software modular y compatibles con otro software



    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/

#include <iostream>
#include <string>
#include "API.h"
#include "nutricion_usuario.h"
#include "json_handler.h"

std::pair<std::string, std::string> loadAPIConfig() {
    return {"66c863b9", "3b797da8030d8bbace629fccab47de17"};
}

int main() {
    try {
        auto [app_id, app_key] = loadAPIConfig();
        API api(app_id, app_key);
        
        std::string recipe;
        std::cout << "Ingrese la receta: ";
        std::getline(std::cin, recipe);
        
        std::string jsonResponse = api.getNutritionData(recipe);
        NutritionDisplayer::display(jsonResponse);
        JsonHandler::saveToFile(jsonResponse, "nutrition_data.json");
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}