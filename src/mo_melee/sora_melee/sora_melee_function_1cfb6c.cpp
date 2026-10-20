#pragma force_active on
typedef unsigned int u32;

struct Fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1CFB6C(Fn27Obj *obj)
{
    obj->flags &= ~0x2000u;
}
