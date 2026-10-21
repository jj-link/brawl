#pragma force_active on
struct GreenHillData {
    unsigned char padding[8];
    unsigned int : 2;
    unsigned int field : 2;
    unsigned int : 28;
};

extern "C" void fn_72_501C(GreenHillData* self, unsigned int value)
{
    self->field = value;
}
