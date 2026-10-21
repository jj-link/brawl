#pragma force_active on
struct Data {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int : 20;
    unsigned int value : 10;
    unsigned int : 2;
};

extern "C" void fn_27_1A453C(Data* self, unsigned int value)
{
    self->value = value;
}
