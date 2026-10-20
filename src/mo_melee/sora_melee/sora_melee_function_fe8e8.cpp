#pragma force_active on
typedef unsigned int u32;

struct fn_27_FE8E8_Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_FE8E8(fn_27_FE8E8_Obj *obj)
{
    obj->flags |= 0x00080000;
}
}
