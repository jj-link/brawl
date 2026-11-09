#pragma force_active on
static inline unsigned int lower(unsigned int min, long long value) {
    if (value < min) return min;
    return value;
}
static inline unsigned int clamp(unsigned int max, long long value) {
    if (value > max) return max;
    return lower(0, value);
}
extern "C" int fn_8015CC44(unsigned int* obj, int delta) {
    if (delta != 0) {
        obj[1] = clamp(obj[0], obj[1] + delta);
    }
    return obj[1];
}