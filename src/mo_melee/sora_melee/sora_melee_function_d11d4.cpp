#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_D11D4(FlagHolder *p)
{
    p->flags |= 0x80;
}
