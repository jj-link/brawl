#pragma force_active on
typedef unsigned int u32;

struct fn_27_Obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 hi : 6;
        u32 field : 3;
        u32 lo : 23;
    } unk8;
};

extern "C" void fn_27_1A1C80(fn_27_Obj* obj, u32 val)
{
    obj->unk8.field = val;
}
