#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int value : 10;
    unsigned int rest : 22;
};

extern "C" void fn_27_1A5F20(State* self, unsigned int value)
{
    self->value = value;
}
