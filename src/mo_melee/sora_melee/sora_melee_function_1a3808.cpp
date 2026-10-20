#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 20;
    u32 field : 10;
    u32 lo : 2;
};

extern "C" void fn_27_1A3808(Obj *obj, u32 val)
{
    obj->field = val;
}
