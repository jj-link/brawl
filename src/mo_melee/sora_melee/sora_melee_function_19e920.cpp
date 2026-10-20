#pragma force_active on
typedef unsigned int u32;

struct fn_27_19E920_obj {
    u32 unk0;
    u32 unk4;
    u32 pad : 10;
    u32 field : 5;
    u32 low : 17;
};

extern "C" {
void fn_27_19E920(fn_27_19E920_obj* obj, u32 val) {
    obj->field = val;
}
}
