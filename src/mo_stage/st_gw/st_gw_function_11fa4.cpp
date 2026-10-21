#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_63_11FA4(State* state) {
    state->flags &= ~0x02000000u;
}
