#pragma force_active on
struct JungleState {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" unsigned int fn_51_67EC(const JungleState* state) {
    return (state->flags >> 19) & 1;
}
