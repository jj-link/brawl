#pragma force_active on
typedef unsigned int u32;

struct fn_27_19BC58_Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_19BC58(fn_27_19BC58_Obj* p) {
    p->flags &= ~0x00010000;
}
}
