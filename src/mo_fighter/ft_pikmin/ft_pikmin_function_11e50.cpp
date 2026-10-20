#pragma force_active on
struct PikminState {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" void fn_113_11E50(PikminState* self) {
    self->flags &= ~0x02000000u;
}
