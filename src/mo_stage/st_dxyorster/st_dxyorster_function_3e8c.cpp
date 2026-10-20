#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int field;
} S;

extern "C" int fn_76_3E8C(S *p)
{
    unsigned int x = p->field;
    return (int)(((x << 5) | (x >> 27)) & 0xFC000000u) >> 27;
}
