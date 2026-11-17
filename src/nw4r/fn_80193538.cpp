#include <revolution/OS/OSFastCast.h>
#pragma force_active on

extern "C" const void* fn_80193538(const void* arg0, float value) {
    const unsigned char* base = (const unsigned char*)arg0;
    unsigned int count = *(const u16*)base;
    const float* first = (const float*)(base + 8);
    float firstKey = *first;
    const float* last = (const float*)(base + 8 + (count - 1) * 8);

    if (value <= firstKey)
        return first;
    if (*last <= value)
        return last;

    u16 conversionCount = count;
    float delta = value - firstKey;
    float countAsFloat = __OSu16tof32(&conversionCount);
    float weightedDelta = delta * countAsFloat;
    float scaledDelta = *(const float*)(base + 4) * weightedDelta;
    u16 index = __OSf32tou16(scaledDelta);
    const float* entry = (const float*)(base + 8 + index * 8);

    if (value < *entry) {
        do {
            entry -= 2;
        } while (value < *entry);
        return entry;
    }

    do {
        entry += 2;
    } while (*entry <= value);
    return entry - 2;
}
