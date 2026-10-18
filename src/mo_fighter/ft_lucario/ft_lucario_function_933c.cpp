#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void fn_118_933C(Vec3* destination, const Vec3* source) {
    destination->x = source->x;
    destination->y = source->y;
    destination->z = source->z;
}
