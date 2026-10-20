#pragma force_active on
struct OnettState {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_78_56F8(const OnettState* state) {
    return (state->flags >> 25) & 1u;
}
