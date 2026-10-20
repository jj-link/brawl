#pragma force_active on
typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern "C" void fn_40_38CB4(Vec3* v, float x, float y, float z) {
    v->x = x;
    v->y = y;
    v->z = z;
}
