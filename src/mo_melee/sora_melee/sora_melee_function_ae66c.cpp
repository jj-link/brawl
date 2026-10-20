#pragma force_active on
struct FooObj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_AE66C(FooObj* p) {
    p->flags &= ~0x02000000;
}
}
