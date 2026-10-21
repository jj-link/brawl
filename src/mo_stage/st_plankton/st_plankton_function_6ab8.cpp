#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int : 4;
    unsigned int field : 2;
    unsigned int : 26;
};

extern "C" void fn_74_6AB8(State* state, unsigned int value)
{
    state->field = value;
}
