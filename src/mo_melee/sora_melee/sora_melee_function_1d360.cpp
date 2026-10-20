#pragma force_active on
typedef unsigned int u32;

struct fn_27_1D360_Obj {
    u32 unk0;
    u32 unk4;
    u32 flags8;
};

extern "C" {
void fn_27_1D360(fn_27_1D360_Obj* p) {
    p->flags8 &= ~0x2000;
}
}
