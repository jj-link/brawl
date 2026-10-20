#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct fn_27_CAA40_Obj {
    u8 pad[8];
    u32 flags;
};

extern "C" {
void fn_27_CAA40(fn_27_CAA40_Obj* obj) {
    obj->flags &= ~0x10000;
}
}
