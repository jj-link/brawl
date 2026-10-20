#pragma force_active on
struct FlagObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_27_1A39DC(FlagObj *p) {
    p->flags &= ~2u;
}
