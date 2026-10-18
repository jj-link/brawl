#pragma force_active on
struct Data {
    unsigned int value;
    float first;
    float second;
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
};

extern "C" void fn_92_EBE0(Data* out, unsigned int value, float first, float second,
                           unsigned char byte0, unsigned char byte1,
                           unsigned char byte2, unsigned char byte3)
{
    out->value = value;
    out->first = first;
    out->second = second;
    out->byte0 = byte0;
    out->byte1 = byte1;
    out->byte2 = byte2;
    out->byte3 = byte3;
}
