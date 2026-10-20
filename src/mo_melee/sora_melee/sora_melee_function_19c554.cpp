#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 8;
    u32 field : 4;
    u32 lo : 20;
};

extern "C" void fn_27_19C554(Obj* obj, u32 val)
{
    obj->field = val;
}
