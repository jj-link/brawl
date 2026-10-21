#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int high : 8;
    unsigned int value : 4;
    unsigned int low : 20;
};

extern "C" void fn_27_19BA44(Data* self, unsigned int value)
{
    self->value = value;
}
