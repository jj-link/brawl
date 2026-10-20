#pragma force_active on
typedef unsigned int u32;

struct FnBits {
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

struct FnObj {
    u32 unk0;
    u32 unk4;
    FnBits flags;
};

extern "C" void fn_27_19D67C(FnObj* p, u32 v)
{
    p->flags.b = v;
}
