#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int upper : 8;
    unsigned int field : 4;
    unsigned int lower : 20;
};

extern "C" void fn_27_1D0178(State* self, unsigned int value)
{
    self->field = value;
}
