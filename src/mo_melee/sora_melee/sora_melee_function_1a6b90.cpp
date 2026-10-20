#pragma force_active on
struct FnObj32 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_1A6B90(FnObj32 *p) {
    p->flags |= 0x2;
}
}
