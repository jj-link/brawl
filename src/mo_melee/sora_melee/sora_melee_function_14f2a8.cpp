#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_27_14F2A8(State* self) {
    self->flags &= ~0x400u;
}
