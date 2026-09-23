#ifndef P2A_H
#define P2A_H

#include <cassert>
#include <cstdint>
#include <cmath>

inline uint64_t expand(uint64_t input, uint32_t scale) {
    if (scale > 16)
    {
        assert(("Shift scale cannot exceed 16", false));
    }

    auto inputCopy = input;
    int n = 0;

    while (pow(2, n) <= inputCopy)
    {
        n++;
    }

    uint64_t shiftedInput = 0;

    while (n > 0)
    {
        uint64_t bit = pow(2, n-1);
        uint64_t tempBit = input & bit;
        if (tempBit != 0)
        {
            tempBit = 1;
            tempBit = tempBit << ((n-1) * scale);
            shiftedInput = shiftedInput | tempBit;
        }
        n--;
    }
    return shiftedInput; 
}

inline uint64_t morton3d(uint64_t x, uint64_t y, uint64_t z)
{
    uint64_t expandedX = expand(x, 3);
    uint64_t expandedY = expand(y, 3);
    uint64_t expandedZ = expand(z, 3);

    expandedY = expandedY << 1;
    expandedZ = expandedZ << 2;

    uint64_t morton = expandedX & expandedY & expandedZ;

    return morton;
}

#endif  // P2A_H