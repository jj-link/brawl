#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_11BA2C(FlagHolder* p)
{
    p->flags &= ~0x00080000;
}
