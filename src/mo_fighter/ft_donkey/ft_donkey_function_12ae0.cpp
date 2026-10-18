#pragma force_active on
struct FtDonkeyData {
    int pad0;
    int pad1;
    void *field8;
    void *fieldC;
    void *field10;
};

extern "C" void fn_92_12AE0(FtDonkeyData *self, void *value)
{
    self->field10 = value;
    self->fieldC = value;
    self->field8 = value;
}
