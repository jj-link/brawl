#pragma force_active on
typedef unsigned int u32;

typedef struct {
    int pad[2];
    u32 hi : 6;
    u32 rest : 26;
} S;

extern "C" void fn_79_58D0(S *p, u32 v)
{
    p->hi = v;
}
