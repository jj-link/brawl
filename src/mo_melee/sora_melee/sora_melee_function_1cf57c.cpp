#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
    u32 pad0 : 3;
    u32 f : 3;
    u32 rest : 26;
} S;

extern "C" {
void fn_27_1CF57C(S* p, u32 v)
{
    p->f = v;
}
}
