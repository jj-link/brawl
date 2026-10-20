#include <math.h>
#pragma force_active on

struct V2 {
    float x, y;
};

inline float absf(float value) {
    return (float)__fabs(value);
}

extern "C" float fn_41_25268(void*, unsigned long, V2, V2, unsigned long);

extern "C" bool fn_41_2536C(void* acc, unsigned long target,
                            V2 first, V2 second,
                            unsigned long mode, float limit) {
    float value = fn_41_25268(acc, target, first, second, mode);
    float absLimit = absf(limit);
    return absf(value) <= absLimit;
}
