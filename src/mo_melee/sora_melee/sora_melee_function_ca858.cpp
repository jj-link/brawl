#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad0;
    u32 pad1;
    u32 a : 5;
    u32 b : 27;
} S;

extern "C" {
void fn_27_CA858(S *p, u32 v)
{
    p->a = v;
}
}
