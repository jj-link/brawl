#pragma force_active on
typedef unsigned int u32;

struct fn_27_1D09CC_obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
void fn_27_1D09CC(fn_27_1D09CC_obj* p) {
    p->unk8 &= ~0x00080000;
}
}
