#pragma force_active on
struct Vec3 {
    float x, y, z;
};

extern "C" void fn_109_8B54(Vec3* vector, float x, float y, float z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
