#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 pad0;
    u32 pad1;
    u32 flags;
} FnObj;

extern "C" void fn_54_661C(FnObj *p)
{
    p->flags |= 0x02000000;
}
