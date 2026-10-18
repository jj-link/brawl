#pragma force_active on
struct Vec3f {
    float x, y, z;
};

extern "C" void fn_120_8718(Vec3f* vector, float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
