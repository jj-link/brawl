#pragma force_active on
struct Vec3F {
    float x, y, z;
};

extern "C" void fn_102_C5B8(Vec3F* vector, float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
