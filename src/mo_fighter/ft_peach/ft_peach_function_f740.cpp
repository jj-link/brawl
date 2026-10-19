#pragma force_active on
struct PeachState {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_103_F740(PeachState* state) {
    state->flags &= ~0x2000u;
}
