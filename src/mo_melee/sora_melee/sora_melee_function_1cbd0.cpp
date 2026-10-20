#pragma force_active on
struct State {
    unsigned int words[3];
};

extern "C" void fn_27_1CBD0(State *state)
{
    state->words[0] = 0;
    state->words[1] = 0;
    state->words[2] = 0;
}
