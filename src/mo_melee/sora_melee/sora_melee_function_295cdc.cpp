#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int : 6;
    unsigned int value : 3;
    unsigned int : 23;
};

extern "C" void fn_27_295CDC(State* self, unsigned int value)
{
    self->value = value;
}
