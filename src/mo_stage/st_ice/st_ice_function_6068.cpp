#pragma force_active on
typedef unsigned long u32;

typedef struct StFlagHolder
{
    u32 pad0;
    u32 pad1;
    u32 flags;
} StFlagHolder;

extern "C" {
void fn_62_6068(StFlagHolder *p)
{
    p->flags |= 0x02000000;
}
}
