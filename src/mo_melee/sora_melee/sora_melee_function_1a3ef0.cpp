#pragma force_active on
struct fn_27_1A3EF0_Obj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_27_1A3EF0(fn_27_1A3EF0_Obj* self) {
    self->flags &= ~0x2u;
}
}
