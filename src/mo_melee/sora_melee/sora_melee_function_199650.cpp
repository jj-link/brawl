#pragma force_active on
typedef unsigned int u32;

struct fn_27_199650_obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_199650(fn_27_199650_obj* p) {
    p->flags &= ~0x00400000u;
}
}
