#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
    u32 pad0 : 7;
    u32 f : 7;
    u32 pad1 : 18;
} S;

extern "C" {
void fn_27_14F278(S *p, u32 v)
{
    p->f = v;
}
}
