#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" void fn_98_F5B0(Vec3f* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
