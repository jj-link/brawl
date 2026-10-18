#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_63_B08C(State* self) {
    self->flags &= ~0x00080000u;
}
