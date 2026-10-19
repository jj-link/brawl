#pragma force_active on
struct Vec3PadF {
    float pad;
    float x;
    float y;
    float z;
};

extern "C" void fn_46_67F0(Vec3PadF* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
