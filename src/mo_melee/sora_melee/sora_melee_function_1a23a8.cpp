#pragma force_active on
typedef unsigned int u32;

struct FnBits {
    u32 hi : 4;
    u32 field : 4;
    u32 lo : 24;
};

struct FnTarget {
    u32 unk0;
    u32 unk4;
    FnBits unk8;
};

extern "C" void fn_27_1A23A8(FnTarget* p, u32 v)
{
    p->unk8.field = v;
}
