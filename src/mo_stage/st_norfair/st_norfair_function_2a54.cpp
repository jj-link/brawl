#pragma force_active on
struct Fn54_2A54Data
{
    unsigned char pad[0x188];
    int value;
    float floatValue;
};

extern "C" void fn_54_2A54(Fn54_2A54Data* self, int* outValue, float* outFloat)
{
    *outValue = self->value;
    *outFloat = self->floatValue;
}
