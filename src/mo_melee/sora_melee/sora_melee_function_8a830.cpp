#pragma force_active on
typedef struct {
    float x;
    float y;
    float z;
} Vec3;

typedef struct {
    char pad[8];
    Vec3 v;
} Dst;

extern "C" void fn_27_8A830(void* a, void* b, void* c, const Vec3* src)
{
    Dst* d = (Dst*)a;
    d->v.x = src->x;
    d->v.y = src->y;
    d->v.z = src->z;
}
