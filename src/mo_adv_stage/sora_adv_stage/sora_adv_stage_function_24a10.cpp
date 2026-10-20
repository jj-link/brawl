#pragma force_active on
struct Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_40_24A10(Obj* p) {
    p->flags |= 0x02000000;
}
}
