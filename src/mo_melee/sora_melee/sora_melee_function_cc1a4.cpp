#pragma force_active on
typedef unsigned int u32;

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_CC1A4(fn27Obj* p) {
    p->flags |= 0x02000000;
}
}
