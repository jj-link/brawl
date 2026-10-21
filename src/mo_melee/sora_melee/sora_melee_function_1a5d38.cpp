#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int upper : 10;
    unsigned int field : 10;
    unsigned int lower : 12;
};

extern "C" void fn_27_1A5D38(Data* self, unsigned int value)
{
    self->field = value;
}
