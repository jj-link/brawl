#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A73F8_Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
void fn_27_1A73F8(fn_27_1A73F8_Obj* p) {
    p->unk8 |= 0x80000;
}
}
