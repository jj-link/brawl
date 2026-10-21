#pragma force_active on
struct State
{
    unsigned int padding[2];
    unsigned int : 7;
    unsigned int field : 7;
    unsigned int : 18;
};

extern "C" void fn_48_B8A8(State* self, unsigned int value)
{
    self->field = value;
}
