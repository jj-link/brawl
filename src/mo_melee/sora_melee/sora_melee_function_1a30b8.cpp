#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct FnObj {
    u8 pad[8];
    u32 flags;
} FnObj;

extern "C" {
void fn_27_1A30B8(FnObj *p)
{
    p->flags &= ~0x00400000;
}
}
