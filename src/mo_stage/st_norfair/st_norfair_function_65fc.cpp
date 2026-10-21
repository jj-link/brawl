#pragma force_active on
struct NorfairData
{
    unsigned int padding[2];
    unsigned int : 2;
    unsigned int value : 2;
    unsigned int : 28;
};

extern "C" void fn_54_65FC(NorfairData* self, unsigned int value)
{
    self->value = value;
}
