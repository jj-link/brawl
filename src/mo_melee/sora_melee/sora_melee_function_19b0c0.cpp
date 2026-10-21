#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int : 5;
    unsigned int field : 5;
    unsigned int : 22;
};

extern "C" void fn_27_19B0C0(State* self, unsigned int value)
{
    self->field = value;
}
