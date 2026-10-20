#pragma force_active on
struct HalberdState {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_57_AD2C(const HalberdState* state) {
    return (state->flags >> 25) & 1;
}
