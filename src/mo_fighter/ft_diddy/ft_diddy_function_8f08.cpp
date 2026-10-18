#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" void fn_115_8F08(Vec3f* destination, const Vec3f* source) {
    destination->x = source->x;
    destination->y = source->y;
    destination->z = source->z;
}
