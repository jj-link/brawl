#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
} FlagObj;

extern "C" void fn_27_19FD70(FlagObj *p)
{
    p->flags |= 0x00400000;
}
