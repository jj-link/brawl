#pragma force_active on
struct Data
{
    unsigned int padding[2];
    unsigned int high : 20;
    unsigned int value : 10;
    unsigned int low : 2;
};

extern "C" void fn_27_1A5B94(Data* self, unsigned int value)
{
    self->value = value;
}
