#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int value : 3;
    unsigned int flags : 29;
};

extern "C" void fn_27_FF2B8(State* self, unsigned int value)
{
    self->value = value;
}
