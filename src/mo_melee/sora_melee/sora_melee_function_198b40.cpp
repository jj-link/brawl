#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
} FnObj;

extern "C" void fn_27_198B40(FnObj *obj)
{
    obj->flags &= ~0x00080000;
}
