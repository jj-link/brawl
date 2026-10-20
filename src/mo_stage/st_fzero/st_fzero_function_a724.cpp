#pragma force_active on
typedef unsigned int u32;

struct FzeroObj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_61_A724(FzeroObj* p) {
    p->flags |= 0x02000000;
}
