#pragma force_active on
typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct Dst {
    unsigned int pad[2];
    Vec3f v;
} Dst;

extern "C" void fn_27_2B4AEC(Dst* dst, int unused1, int unused2, const Vec3f* src) {
    dst->v = *src;
}
