#pragma force_active on
struct State {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" unsigned int fn_71_9EF4(const State* state) {
    return (state->flags >> 25) & 1;
}
