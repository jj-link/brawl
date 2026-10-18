#pragma force_active on
struct Vec3 {
    float z;
    float x;
    float y;
};

extern "C" float fn_102_1BE90(float *obj) {
    return obj[2] * obj[3];
}
