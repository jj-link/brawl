#pragma force_active on
struct Obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_FE618(Obj* p) {
    p->flags &= 0xFDFFFFFFu;
}
}
