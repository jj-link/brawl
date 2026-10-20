#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    char pad[8];
    u32 flags;
};

extern "C" void fn_27_AAA68(FlagHolder *p)
{
    p->flags |= 0x10000;
}
