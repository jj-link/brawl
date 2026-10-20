#pragma force_active on
struct FnObj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_D19A4(FnObj* p) {
    p->flags &= ~0x00010000;
}
}
