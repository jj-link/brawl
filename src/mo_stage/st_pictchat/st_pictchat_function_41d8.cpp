#pragma force_active on
struct Vec3f {
    float x, y, z;
};

extern "C" void fn_73_41D8(Vec3f* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
