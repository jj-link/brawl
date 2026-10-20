#pragma force_active on
typedef struct {
    int x;
    int y;
    int z;
} Vec3i;

typedef struct {
    int pad[2];
    Vec3i v;
} Vec3iHolder;

extern "C" void fn_27_2B4AD0(Vec3i* dst, const Vec3iHolder* src) {
    *dst = src->v;
}
