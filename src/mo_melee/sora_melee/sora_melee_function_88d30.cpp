#pragma force_active on
struct Obj27 {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_88D30(Obj27* p) {
    p->flags &= ~0x2000u;
}
}
