#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int v;
} FooStruct;

extern "C" {
int fn_51_64DC(FooStruct *s)
{
    unsigned int x = s->v;
    return (int)((x << 2 | x >> 30) & 0xE0000000u) >> 30;
}
}
