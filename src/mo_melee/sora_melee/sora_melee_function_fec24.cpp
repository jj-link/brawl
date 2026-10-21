#pragma force_active on
struct Data {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int : 4;
    unsigned int field : 2;
    unsigned int : 26;
};

extern "C" void fn_27_FEC24(Data* self, unsigned int value)
{
    self->field = value;
}
