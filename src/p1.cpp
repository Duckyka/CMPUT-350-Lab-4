#include <cstddef>  // size_t
#include <array>
#include <iostream>
#include <random>
#include "timer.h"

constexpr size_t SIZE = 16000000;
constexpr size_t ROWNUM = 4000;
constexpr size_t COLNUM = 4000;

int main()
{
    std::array<std::array<uint64_t, ROWNUM>, COLNUM> row_major_array;
    std::array<std::array<uint64_t, COLNUM>, ROWNUM> column_major_array;

    std::mt19937_64 rng(0);

    //Filling row-major order array. 
    for (size_t i = 0; i < ROWNUM; i++)
    {
        for (size_t j = 0; j < COLNUM; j++)
        {
            row_major_array[i][j] = rng();
        }
    }

    rng.seed(0);
    //Filling column-major order array. 
    for (size_t i = 0; i < ROWNUM; i++)
    {
        for (size_t j = 0; j < COLNUM; j++)
        {
            column_major_array[j][i] = rng();
        }
    }

    Timer timer;
    int64_t row_sum = 0;
    int64_t col_sum = 0; 

    for (size_t i = 0; i < ROWNUM; i++)
    {
        for (size_t j = 0; j < COLNUM; j++)
        {
            row_sum += row_major_array[i][j];
        }
    }
    uint64_t row_major_sumtime = timer.glance<Timer::Micros>();
    
    timer.restart();
    for (size_t i = 0; i < ROWNUM; i++)
    {
        for (size_t j = 0; j < COLNUM; j++)
        {
            col_sum += row_major_array[j][i];
        }
    }
    uint64_t col_major_sumtime = timer.glance<Timer::Micros>();

    std::cout << row_major_sumtime << " " << row_sum << "\n";
    std::cout << col_major_sumtime << " " << col_sum << "\n";

    return 0;
}
