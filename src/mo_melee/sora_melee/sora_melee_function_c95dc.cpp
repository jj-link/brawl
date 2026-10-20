#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_C95DC(FlagHolder *p)
{
    p->flags |= 0x00400000;
}
