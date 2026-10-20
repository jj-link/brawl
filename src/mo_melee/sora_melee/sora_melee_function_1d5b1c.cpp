#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 high : 10;
    u32 field : 5;
    u32 low : 17;
};

extern "C" void fn_27_1D5B1C(Obj* obj, u32 val) {
    obj->field = val;
}
