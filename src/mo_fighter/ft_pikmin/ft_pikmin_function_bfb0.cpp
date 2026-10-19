#pragma force_active on
extern "C" unsigned long long fn_113_BFB0(const float *a, const float *b)
{
    union {
        struct { float x, y; } values;
        unsigned long long packed;
    } result;

    result.values.x = a[0] - b[0];
    result.values.y = a[1] - b[1];
    return result.packed;
}
