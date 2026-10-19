#pragma force_active on
struct State {
    unsigned char prefix[8];
    unsigned long long value;
};

extern "C" unsigned long long fn_91_CD30(const State* state) {
    return state->value;
}
