#include <iostream>
#include <memory>
#include <windows.h>

#include "shared_types.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "Лабораторна робота №1\n";
    std::cout << "Варіант 10 - Чисельне диференціювання\n";
    std::cout << "Студент А - однобічні скінченні різниці\n\n";

    // Таблиця для функції y = x^2
    std::vector<Point> points =
    {
        {0.0, 0.0},
        {1.0, 1.0},
        {2.0, 4.0},
        {3.0, 9.0},
        {4.0, 16.0}
    };

    // Створюємо спільні вхідні дані
    auto data = std::make_shared<const InputData>(
        InputData{points, 2.0});

    // Викликаємо алгоритм Студента А
    auto resultA = calculateA(data);

    // Structured bindings
    auto [derivativeA, errorA] = *resultA;

    std::cout << "Точка x0 = " << data->x0 << "\n";
    std::cout << "Наближене значення похідної: "
              << derivativeA << "\n";

    std::cout << "Оцінка похибки: "
              << errorA << "\n";

    return 0;
}