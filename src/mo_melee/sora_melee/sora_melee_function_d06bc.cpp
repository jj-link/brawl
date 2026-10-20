#pragma force_active on
typedef unsigned int u32;

typedef struct {
    char pad[8];
    u32 flags;
} FnObj;

extern "C" void fn_27_D06BC(FnObj *p)
{
    p->flags &= ~0x400;
}
