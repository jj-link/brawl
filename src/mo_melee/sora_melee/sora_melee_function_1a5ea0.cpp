#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 unk0;
    u32 unk4;
    u32 unk8 : 20;
    u32 field : 10;
    u32 pad : 2;
};

extern "C" void fn_27_1A5EA0(S* obj, u32 val) {
    obj->field = val;
}
