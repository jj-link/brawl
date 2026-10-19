#pragma force_active on
typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Raw {
    unsigned int x;
    unsigned int y;
    unsigned int z;
} Raw;

typedef union Bits {
    Raw r;
    Vec3 v;
} Bits;

typedef struct Src {
    char pad[0x40];
    Raw a;
    Raw b;
    float c;
} Src;

extern "C" void fn_20_DBA4(Src *s, Vec3 *out1, Vec3 *out2, float *out3)
{
    Bits t1;
    Bits t2;
    t1.r = *(Raw *)&s->a;
    *out1 = t1.v;
    t2.r = *(Raw *)&s->b;
    *out2 = t2.v;
    *out3 = s->c;
}
