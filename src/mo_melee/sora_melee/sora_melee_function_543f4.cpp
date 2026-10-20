#pragma force_active on
typedef unsigned int u32;

struct fn_27_543F4_obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_543F4(fn_27_543F4_obj* obj)
{
    obj->flags |= 0x10;
}
