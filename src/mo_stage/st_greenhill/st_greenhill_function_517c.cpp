#pragma force_active on
extern "C" {
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
    u32 a : 2;
    u32 b : 2;
    u32 rest : 28;
} S;

void fn_72_517C(S *p, u32 v)
{
    p->b = v;
}
}
