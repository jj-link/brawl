#pragma force_active on
struct JungleState {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" unsigned int fn_51_592C(const JungleState* state) {
    return (state->flags >> 25) & 1;
}
