#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_FE8F8(FnObj* p)
{
    p->flags &= ~0x80000;
}
