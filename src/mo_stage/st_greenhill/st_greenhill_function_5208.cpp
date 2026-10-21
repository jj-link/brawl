#pragma force_active on
struct GreenHillState {
    unsigned char padding[8];
    unsigned int : 4;
    unsigned int flags : 2;
    unsigned int : 26;
};

extern "C" void fn_72_5208(GreenHillState* self, unsigned int value)
{
    self->flags = value;
}
