#pragma force_active on
struct State {
    unsigned char padding[0x40];
    unsigned char value;
};

extern "C" bool fn_27_2423E4(const State* state) {
    if (state->value == 3)
        return true;
    return state->value == 0;
}
