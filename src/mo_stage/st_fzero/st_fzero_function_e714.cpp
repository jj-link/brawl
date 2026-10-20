#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int v;
} St;

extern "C" int fn_61_E714(St *p)
{
    return (int)((p->v << 3) & 0xF0000000u) >> 29;
}
