#pragma force_active on
typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct SrcObj {
    char pad[0x29c];
    Vec3f pos;
} SrcObj;

extern "C" void fn_27_230E44(SrcObj *src, Vec3f *dst)
{
    dst->x = src->pos.x;
    dst->y = src->pos.y;
    dst->z = src->pos.z;
}
