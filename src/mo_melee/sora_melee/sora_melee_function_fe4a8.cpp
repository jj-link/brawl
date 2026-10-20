#pragma force_active on
struct FnObj27 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" void fn_27_FE4A8(FnObj27* p) {
    p->flags &= ~0x02000000;
}
