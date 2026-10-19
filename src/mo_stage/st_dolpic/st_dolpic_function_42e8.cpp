#pragma force_active on
struct Fn46_42E8Data
{
    unsigned char padding[0x184];
    unsigned char byteValue;
    unsigned char padding2[3];
    unsigned int wordValue;
    float floatValue;
};

extern "C" void fn_46_42E8(Fn46_42E8Data* data, unsigned char byteValue, unsigned int wordValue, float floatValue)
{
    data->byteValue = byteValue;
    data->wordValue = wordValue;
    data->floatValue = floatValue;
}
