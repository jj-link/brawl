#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int upper : 12;
    unsigned int value : 6;
    unsigned int lower : 14;
};

extern "C" void fn_27_29614C(State* self, unsigned int value)
{
    self->value = value;
}
