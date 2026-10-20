#pragma force_active on
struct PiratesData {
    unsigned char padding[0x51C];
    unsigned int field_51C;
    unsigned int field_520;
    unsigned int field_524;
};

extern "C" void fn_52_13630(PiratesData* self, unsigned int a, unsigned int b)
{
    self->field_51C = a;
    self->field_524 = b;
}
