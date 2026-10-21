#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_79_5CA8(State* self) {
    self->flags &= ~0x00080000u;
}
