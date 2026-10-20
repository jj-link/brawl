#pragma force_active on
typedef unsigned int u32;

struct Hi {
    u32 pad[2];
    u32 a : 4;
    u32 rest : 28;
};

extern "C" {
void fn_27_19F3A0(Hi *p, u32 v)
{
    p->a = v;
}
}
