#pragma force_active on
struct fn27Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_389E0C(fn27Obj* p) {
    p->flags &= ~0x80000;
}
}
