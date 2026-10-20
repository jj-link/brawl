#pragma force_active on
typedef unsigned int u32;

struct FlagObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" {
void fn_27_395880(FlagObj* p) {
    p->flags &= ~0x00080000;
}
}
