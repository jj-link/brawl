#pragma force_active on
struct JungleState {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_51_651C(JungleState* self) {
    self->flags &= ~0x02000000u;
}
