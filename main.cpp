#include <iostream>
#include <memory>
#include <windows.h>

#include "shared_types.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "Лабораторна робота №1\n";
    std::cout << "Варіант 10 | Студент B\n";
    


    std::vector<Point> points =
    {
        {0.0, 0.0},
        {1.0, 1.0},
        {2.0, 4.0},
        {3.0, 9.0},
        {4.0, 16.0}
    };


    auto data = std::make_shared<const InputData>( //створення вхідних даних
        InputData{points, 2.0});


    auto resultB = calculateB(data);

  
    auto [derivativeB, errorB] = *resultB;

    std::cout << "Точка x0=" << data->x0 << "\n";
    std::cout << "Наближене значення похідної:"
              << derivativeB << "\n";

    std::cout << "Оцінка похибки:"
              << errorB << "\n";

    return 0;
}