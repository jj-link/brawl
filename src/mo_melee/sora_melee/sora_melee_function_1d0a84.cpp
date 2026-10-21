#pragma force_active on
struct State {
    unsigned int reserved[2];
    unsigned int flags;
};

extern "C" void fn_27_1D0A84(State* state) {
    state->flags &= ~0x00400000u;
}
