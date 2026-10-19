#pragma force_active on
struct Result {
    unsigned int x;
    unsigned int y;
};

extern "C" Result fn_41_24110(float* a, float* b) {
    Result r;
    float x = a[0] - b[0];
    *(float*)&r.x = x;
    float y = a[1] - b[1];
    *(float*)&r.y = y;
    return r;
}
