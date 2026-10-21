#pragma force_active on
struct State {
    unsigned char padding[8];
    unsigned int high : 16;
    unsigned int value : 8;
    unsigned int low : 8;
};

extern "C" void fn_27_CE248(State* self, unsigned int value)
{
    self->value = value;
}
