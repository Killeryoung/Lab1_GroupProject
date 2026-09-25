#include "shared_types.h"

#include <cmath>


std::unique_ptr<Result> calculateB(
    std::shared_ptr<const InputData> data)
{

    for (std::size_t i = 0; i < data->points.size(); ++i) //шукаємо точку x0 у таблиці
    {
        if (std::abs(data->points[i].x-data->x0)<1e-9)
        {

            if (i>0 && i+1 < data->points.size()) // чи є сусідні точки
            {
                double x1=data->points[i-1].x;
                double y1=data->points[i-1].y;

                double x2=data->points[i+1].x;
                double y2=data->points[i+1].y;

                
                double derivative=(y2-y1)/(x2-x1); // Формула центральної різниці

                // Оцінку похибки зробимо порівнянням
                // з правою однобічною різницею
                double x_right=data->points[i+1].x;
                double y_right=data->points[i+1].y;
                double x_mid=data->points[i].x;
                double y_mid=data->points[i].y;

                double one_sided =
                    (y_right-y_mid)/(x_right-x_mid);

                double error=std::abs(derivative-one_sided);

                return std::make_unique<Result>(
                    Result{derivative, error});
            }


        }
    }


}