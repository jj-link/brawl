#pragma force_active on
typedef unsigned int u32;

typedef struct FnObj
{
    u32 unk0;
    u32 unk4;
    u32 flags;
} FnObj;

extern "C" void fn_27_19FF18(FnObj *obj)
{
    obj->flags &= ~0x00080000;
}
