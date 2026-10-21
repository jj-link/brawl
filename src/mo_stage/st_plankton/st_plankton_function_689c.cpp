#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int : 2;
    unsigned int value : 2;
    unsigned int : 28;
};

extern "C" void fn_74_689C(State* self, unsigned int value)
{
    self->value = value;
}
