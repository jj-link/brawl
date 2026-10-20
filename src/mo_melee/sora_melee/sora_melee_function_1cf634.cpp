#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 a : 2;
    u32 b : 1;
    u32 f : 3;
    u32 rest : 26;
};

struct Holder {
    u32 pad[2];
    Flags flags;
};

extern "C" {
void fn_27_1CF634(Holder *p, u32 v)
{
    p->flags.f = v;
}
}
