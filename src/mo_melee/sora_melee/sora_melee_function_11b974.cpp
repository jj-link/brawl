#pragma force_active on
typedef unsigned int u32;

struct Obj11B974 {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_11B974(Obj11B974* p) {
    p->flags &= ~0x10000;
}
