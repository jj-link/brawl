#pragma force_active on
struct MarioAdapterState {
    unsigned char prefix[12];
    int* values;
};

extern "C" {
int fn_91_A910(MarioAdapterState* state, int idx)
{
    return state->values[idx];
}
}
