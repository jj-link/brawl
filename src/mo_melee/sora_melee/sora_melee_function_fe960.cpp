#pragma force_active on
typedef unsigned int u32;

struct fn_27_FE960_Obj {
    u32 unk0;
    u32 unk4;
    u32 mode : 3;
    u32 rest : 29;
};

extern "C" {
void fn_27_FE960(fn_27_FE960_Obj* obj, u32 val) {
    obj->mode = val;
}
}
