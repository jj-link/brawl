#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int value : 2;
    unsigned int remaining : 30;
};

extern "C" void fn_27_2648A4(State* self, unsigned int value)
{
    self->value = value;
}
