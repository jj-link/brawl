#pragma force_active on
typedef unsigned int u32;

struct FlagHolder {
    u32 pad[2];
    u32 flags;
};

extern "C" void fn_27_CCA48(FlagHolder *p)
{
    p->flags &= ~0x02000000;
}
