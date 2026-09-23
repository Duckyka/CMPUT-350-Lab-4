#include "p2a.h"
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

constexpr size_t XYZ_SIZE = 16777216;

int main()
{
    uint64_t stdArray[256][256][256];
    uint64_t mortonArray[XYZ_SIZE];

    std::mt19937_64 rng(0);

    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            for (int k = 0; k < 256; k++)
            {
                stdArray[i][j][k] = rng();
            }
        }
    }

    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            for (int k = 0; k < 256; k++)
            {
                mortonArray[morton3d(i, j, k)] = stdArray[i][j][k];
            }
        }
    }

    return 0;
}
