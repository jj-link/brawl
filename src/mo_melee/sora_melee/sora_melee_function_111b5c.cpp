#pragma force_active on
typedef struct {
    float x;
    float y;
    float z;
} Vec3f;

struct Target {
    char pad[0x4d8];
    float x;
    float y;
    float z;
};

extern "C" void fn_27_111B5C(Target **t, const Vec3f *v)
{
    Target *p = *t;
    p->x = v->x;
    p->y = v->y;
    p->z = v->z;
}
