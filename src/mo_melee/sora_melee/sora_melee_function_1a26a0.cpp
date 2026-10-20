#pragma force_active on
typedef unsigned int u32;

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 top : 4;
    u32 rest : 28;
};

extern "C" {
void fn_27_1A26A0(fn27Obj* obj, u32 value) {
    obj->top = value;
}
}
