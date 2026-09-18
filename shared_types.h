#pragma once

#include <vector>
#include <memory>

// Одна точка табличної функції
struct Point
{
    double x;
    double y;
};

// Спільні вхідні дані
struct InputData
{
    std::vector<Point> points;
    double x0; // точка, в якій шукаємо похідну
};

// Результат роботи алгоритму
struct Result
{
    double derivative; // наближене значення похідної
    double error;      // оцінка похибки
};

// Алгоритм Студента А
std::unique_ptr<Result> calculateA(
    std::shared_ptr<const InputData> data);

// Алгоритм Студента Б
std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> data);