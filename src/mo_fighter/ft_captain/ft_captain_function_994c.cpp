#pragma force_active on
struct CaptainState
{
    char padding[0x14];
    const float* values;
};

extern "C" float fn_100_994C(const CaptainState* state, int index)
{
    return state->values[index];
}
