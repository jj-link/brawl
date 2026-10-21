#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int : 8;
    unsigned int value : 4;
    unsigned int : 20;
};

extern "C" void fn_27_D2B9C(State* self, unsigned int value)
{
    self->value = value;
}
