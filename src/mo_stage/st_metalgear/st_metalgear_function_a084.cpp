#pragma force_active on
struct MetalGearState {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" unsigned int fn_71_A084(const MetalGearState* state)
{
    return (state->flags >> 25) & 1;
}
