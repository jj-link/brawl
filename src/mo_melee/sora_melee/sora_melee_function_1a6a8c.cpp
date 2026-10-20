#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A6A8C_Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_1A6A8C(fn_27_1A6A8C_Obj* obj) {
    obj->flags |= 2;
}
}
