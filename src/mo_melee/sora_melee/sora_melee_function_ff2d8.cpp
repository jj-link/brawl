#pragma force_active on
typedef unsigned int u32;

struct FnObj {
    u32 unk0;
    u32 unk4;
    u32 top : 3;
    u32 field : 3;
    u32 rest : 26;
};

extern "C" void fn_27_FF2D8(FnObj* obj, u32 val) {
    obj->field = val;
}
