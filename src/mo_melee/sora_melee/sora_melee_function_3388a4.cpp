#pragma force_active on

struct State {
    unsigned char pad[5];
    unsigned char flag : 1;
    unsigned char rest : 7;
    unsigned char status;
    bool enabled() const { return flag; }
};
extern "C" void fn_27_338DAC(State*, void*);
extern "C" void fn_27_3388A4(void* self, void* arg) {
    State* state = (State*)((char*)self + 0x14);
    if (state->enabled() != true) return;
    if (state->status != 0) return;
    fn_27_338DAC(state, arg);
}
