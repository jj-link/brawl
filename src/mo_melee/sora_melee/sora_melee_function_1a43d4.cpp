#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A43D4_Obj {
    u32 unk0;
    u32 unk4;
    u32 hi : 10;
    u32 field : 10;
    u32 lo : 12;
};

extern "C" {
void fn_27_1A43D4(fn_27_1A43D4_Obj* obj, u32 value) {
    obj->field = value;
}
}
