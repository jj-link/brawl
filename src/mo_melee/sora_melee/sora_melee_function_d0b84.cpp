#pragma force_active on
struct fn_27_D0B84_Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_D0B84(fn_27_D0B84_Obj *p) {
    p->flags &= ~0x400u;
}
}
