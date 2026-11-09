#pragma force_active on
static inline unsigned int lower(unsigned int min, long long value) {
    if (value < min) return min;
    return value;
}
static inline unsigned int clamp(unsigned int max, long long value) {
    if (value > max) return max;
    return lower(0, value);
}
extern "C" void fn_8015CCA8(unsigned int* obj, int delta, int mode) {
    switch (mode) {
    case 0: obj[1] = 0; break;
    case 1: break;
    case 2: obj[1] = obj[0]; break;
    }
    if (delta != 0) {
        obj[1] = clamp(obj[0], obj[1] + delta);
    }
}