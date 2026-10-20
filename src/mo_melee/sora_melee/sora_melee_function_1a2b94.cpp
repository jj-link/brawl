#pragma force_active on
typedef unsigned int u32;

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
void fn_27_1A2B94(fn27Obj* p) {
    p->unk8 |= 0x02000000;
}
}
