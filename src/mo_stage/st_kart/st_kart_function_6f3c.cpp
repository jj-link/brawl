#pragma force_active on
struct KartState {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_49_6F3C(const KartState* state)
{
    return (state->flags >> 19) & 1;
}
