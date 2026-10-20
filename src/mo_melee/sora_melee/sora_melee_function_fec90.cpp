#pragma force_active on
struct FecObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_27_FEC90(FecObj* self) {
    self->flags &= ~0x400u;
}
