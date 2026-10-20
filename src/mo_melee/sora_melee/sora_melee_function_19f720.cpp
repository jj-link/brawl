#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 pad0;
    u32 pad4;
    u32 flags;
};

extern "C" void fn_27_19F720(Obj* p)
{
    p->flags &= ~0x80000u;
}
