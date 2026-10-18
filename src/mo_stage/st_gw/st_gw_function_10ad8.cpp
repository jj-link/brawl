#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" unsigned int fn_63_10AD8(const State* state)
{
    return (state->flags >> 25) & 1;
}
