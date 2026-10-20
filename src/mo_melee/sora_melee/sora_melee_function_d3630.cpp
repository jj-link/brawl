#pragma force_active on
typedef unsigned int u32;

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_D3630(fn27Obj* obj)
{
    obj->flags |= 0x10000;
}
}
