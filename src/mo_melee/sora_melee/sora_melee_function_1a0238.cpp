#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    char pad[8];
    u32 flags;
};

extern "C" {
void fn_27_1A0238(FlagHolder* p)
{
    p->flags |= 0x400000;
}
}
