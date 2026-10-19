#pragma force_active on
extern "C" int fn_113_182BC(float f) {
    union {
        float f;
        unsigned int u;
    } v;
    int result;
    v.f = f;
    result = 1;
    if (((v.u >> 23) & 0xff) == 0xff) {
        result = 0;
    }
    return result;
}
