#pragma force_active on
typedef unsigned int u32;

struct Target {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_D29B8(Target *p)
{
    p->flags |= 0x400000;
}
