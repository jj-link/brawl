#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int high : 4;
    unsigned int field : 4;
    unsigned int low : 24;
};

extern "C" void fn_68_D774(State* self, unsigned int value)
{
    self->field = value;
}
