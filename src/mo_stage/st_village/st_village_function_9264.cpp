#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int upper : 4;
    unsigned int field : 2;
    unsigned int lower : 26;
};

extern "C" void fn_70_9264(State* state, unsigned int value)
{
    state->field = value;
}
