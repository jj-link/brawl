#pragma force_active on
struct DonkeyData {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int : 4;
    unsigned int flags : 2;
    unsigned int : 26;
};

extern "C" void fn_50_6340(DonkeyData* self, unsigned int value)
{
    self->flags = value;
}
