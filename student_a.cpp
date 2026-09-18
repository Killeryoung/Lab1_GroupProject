#include "shared_types.h"

#include <cmath>
#include <limits>

std::unique_ptr<Result> calculateA(
    std::shared_ptr<const InputData> data)
{
    // Шукаємо точку x0 у таблиці
    for (std::size_t i = 0; i < data->points.size(); ++i)
    {
        if (std::abs(data->points[i].x - data->x0) < 1e-9)
        {
            // Якщо справа є наступна точка -
            // використовуємо праву однобічну різницю
            if (i + 1 < data->points.size())
            {
                double x1 = data->points[i].x;
                double y1 = data->points[i].y;

                double x2 = data->points[i + 1].x;
                double y2 = data->points[i + 1].y;

                double derivative = (y2 - y1) / (x2 - x1);

                // Оцінку похибки виконаємо порівнянням
                // з центральною різницею, якщо вона доступна
                double error = 0.0;

                if (i > 0 && i + 1 < data->points.size())
                {
                    double central =
                        (data->points[i + 1].y -
                         data->points[i - 1].y) /
                        (data->points[i + 1].x -
                         data->points[i - 1].x);

                    error = std::abs(derivative - central);
                }

                return std::make_unique<Result>(
                    Result{derivative, error});
            }

            // Якщо справа точки немає -
            // використовуємо ліву однобічну різницю
            if (i > 0)
            {
                double x1 = data->points[i - 1].x;
                double y1 = data->points[i - 1].y;

                double x2 = data->points[i].x;
                double y2 = data->points[i].y;

                double derivative = (y2 - y1) / (x2 - x1);

                return std::make_unique<Result>(
                    Result{derivative, 0.0});
            }
        }
    }

    // Якщо x0 не знайдено
    return std::make_unique<Result>(
        Result{
            std::numeric_limits<double>::quiet_NaN(),
            std::numeric_limits<double>::quiet_NaN()
        });
}