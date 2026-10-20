#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad0;
    u32 pad1;
    u32 hi : 5;
    u32 f : 5;
    u32 lo : 22;
} S;

extern "C" {
void fn_27_D2824(S *p, u32 x)
{
    p->f = x;
}
}
