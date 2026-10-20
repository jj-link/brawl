#pragma force_active on
typedef unsigned int u32;

struct fn_27_Obj {
    char pad[8];
    u32 flags;
};

extern "C" {
void fn_27_1D428(fn_27_Obj* obj) {
    obj->flags &= ~0x02000000;
}
}
