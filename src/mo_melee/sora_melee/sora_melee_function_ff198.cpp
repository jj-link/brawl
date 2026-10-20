#pragma force_active on
struct Fn27Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_FF198(Fn27Obj *p) {
    p->flags &= ~0x80000;
}
}
