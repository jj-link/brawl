#pragma force_active on
struct State {
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" void fn_27_D228C(State* self) {
    self->flags &= ~0x00080000u;
}
