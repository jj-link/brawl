#pragma force_active on
struct State {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int flags;
};

extern "C" void fn_27_1992B0(State* state) {
    state->flags &= ~0x2000u;
}
