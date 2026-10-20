#pragma force_active on
struct State {
    unsigned int reserved[2];
    unsigned int flags;
};

extern "C" unsigned int fn_63_AE90(const State* state) {
    return (state->flags >> 25) & 1;
}
