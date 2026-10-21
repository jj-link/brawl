#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int value : 4;
    unsigned int remaining : 28;
};

extern "C" void fn_27_19CF84(State* self, unsigned int value)
{
    self->value = value;
}
