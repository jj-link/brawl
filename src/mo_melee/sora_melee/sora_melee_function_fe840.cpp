#pragma force_active on
struct FE840Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_FE840(FE840Obj *p) {
    p->flags &= ~0x02000000u;
}
}
