#pragma force_active on
struct State {
    unsigned int unused[2];
    unsigned int flags;
};

extern "C" void fn_27_2959D4(State* self) {
    self->flags &= ~0x00080000u;
}
