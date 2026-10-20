#pragma force_active on
typedef unsigned int u32;

struct Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
void fn_27_1D03FC(Obj *p) {
    p->unk8 |= 0x00080000;
}
}
