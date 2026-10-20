#pragma force_active on
typedef unsigned int u32;

struct fn_27_19A298_Obj {
    u32 pad0[2];
    u32 flags;
};

extern "C" {
void fn_27_19A298(fn_27_19A298_Obj* p)
{
    p->flags &= ~0x10000;
}
}
