#pragma force_active on
struct Data {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int : 2;
    unsigned int field : 2;
    unsigned int : 28;
};

extern "C" void fn_27_AE63C(Data* self, unsigned int value)
{
    self->field = value;
}
