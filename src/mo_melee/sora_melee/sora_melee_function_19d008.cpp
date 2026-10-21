#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int upper : 8;
    unsigned int value : 4;
    unsigned int lower : 20;
};

extern "C" void fn_27_19D008(Data* self, unsigned int value)
{
    self->value = value;
}
