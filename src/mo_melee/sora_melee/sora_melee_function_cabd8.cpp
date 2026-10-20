#pragma force_active on
typedef unsigned int u32;

struct fn_27_CABD8_Obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_CABD8(fn_27_CABD8_Obj* p) {
    p->flags &= ~0x2000;
}
}
