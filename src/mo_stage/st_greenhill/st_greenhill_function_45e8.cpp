#pragma force_active on
struct GreenHillState {
    unsigned int unknown0;
    unsigned int unknown4;
    unsigned int flags;
};

extern "C" unsigned int fn_72_45E8(const GreenHillState* state) {
    return (state->flags >> 25) & 1u;
}
