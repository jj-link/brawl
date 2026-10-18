#pragma force_active on
struct Vec3 {
    float x, y, z;
};

extern "C" void fn_111_CB38(Vec3* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
