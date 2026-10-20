#pragma force_active on
typedef unsigned int u32;

struct FnCB10CObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_CB10C(FnCB10CObj* p) {
    p->flags &= ~0x00010000u;
}
}
