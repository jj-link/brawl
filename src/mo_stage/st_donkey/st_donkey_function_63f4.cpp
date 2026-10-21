#pragma force_active on
struct DonkeyData {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int field : 4;
    unsigned int : 28;
};

extern "C" void fn_50_63F4(DonkeyData* self, unsigned int value)
{
    self->field = value;
}
