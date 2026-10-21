#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int : 5;
    unsigned int value : 5;
    unsigned int : 22;
};

extern "C" void fn_27_CE37C(State* self, unsigned int value)
{
    self->value = value;
}
