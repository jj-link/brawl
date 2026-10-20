#pragma force_active on
struct Obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" {
void fn_40_30B3C(Obj* self) {
    self->flags |= 0x10000;
}
}
