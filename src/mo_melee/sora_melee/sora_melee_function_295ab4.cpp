#pragma force_active on
typedef unsigned int u32;

struct Flags {
    u32 hi : 8;
    u32 f : 4;
    u32 lo : 20;
};

struct Obj {
    u32 pad[2];
    Flags flags;
};

extern "C" {
void fn_27_295AB4(Obj* p, u32 v)
{
    p->flags.f = v;
}
}
