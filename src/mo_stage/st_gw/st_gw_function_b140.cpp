#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_63_B140(State* state) {
    state->flags &= ~0x00080000u;
}
