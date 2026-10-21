#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_27_C9C70(State* state) {
    state->flags &= ~0x00400000u;
}
