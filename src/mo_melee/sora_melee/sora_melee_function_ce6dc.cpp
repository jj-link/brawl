#pragma force_active on
struct FnObj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};

extern "C" {
void fn_27_CE6DC(FnObj* p) {
    p->unk8 &= ~0x10u;
}
}
