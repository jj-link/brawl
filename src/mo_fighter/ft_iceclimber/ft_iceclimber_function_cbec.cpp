#pragma force_active on
struct Vec3 { float x; float y; float z; };

extern "C" float fn_105_CBEC(const Vec3* v) {
    return v->z * v->z + (v->x * v->x + v->y * v->y);
}
