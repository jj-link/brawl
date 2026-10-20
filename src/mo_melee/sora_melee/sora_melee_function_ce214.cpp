#pragma force_active on
struct fn_27_CE214_obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_CE214(fn_27_CE214_obj* p) {
    p->flags &= ~0x80u;
}
}
