#pragma force_active on
struct CrayonFlags {
    unsigned int padding[2];
    unsigned int unused : 2;
    unsigned int value : 2;
    unsigned int remaining : 28;
};

extern "C" void fn_56_6358(CrayonFlags* self, unsigned int value)
{
    self->value = value;
}
