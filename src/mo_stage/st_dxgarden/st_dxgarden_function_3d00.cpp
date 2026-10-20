#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int reserved : 4;
    unsigned int value : 2;
    unsigned int remaining : 26;
};

extern "C" void fn_77_3D00(Data* self, unsigned int value)
{
    self->value = value;
}
