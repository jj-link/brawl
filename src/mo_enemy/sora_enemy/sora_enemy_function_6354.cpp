#pragma force_active on
typedef struct { float x; float y; float z; } Vec3;

extern "C" void fn_41_6354(Vec3* v, float s) {
    v->x *= s;
    v->y *= s;
    v->z *= s;
}
