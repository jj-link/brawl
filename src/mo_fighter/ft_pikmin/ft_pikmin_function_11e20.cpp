#pragma force_active on
struct PikminState
{
    unsigned int padding[2];
    unsigned int unused : 2;
    unsigned int mode : 2;
    unsigned int rest : 28;
};

extern "C" void fn_113_11E20(PikminState* self, unsigned int value)
{
    self->mode = value;
}
