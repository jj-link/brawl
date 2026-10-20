#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
} FlagObj;

extern "C" {
void fn_27_2961A8(FlagObj *obj)
{
    obj->flags |= 0x2000;
}
}
