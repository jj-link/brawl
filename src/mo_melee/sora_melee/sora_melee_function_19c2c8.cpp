#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
} Obj;

extern "C" void fn_27_19C2C8(Obj *p)
{
    p->flags |= 0x02000000;
}
