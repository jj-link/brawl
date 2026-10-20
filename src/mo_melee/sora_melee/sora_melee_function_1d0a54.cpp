#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad[2];
    u32 a : 3;
    u32 f : 3;
    u32 b : 26;
} S;

extern "C" void fn_27_1D0A54(S *p, u32 v)
{
    p->f = v;
}
