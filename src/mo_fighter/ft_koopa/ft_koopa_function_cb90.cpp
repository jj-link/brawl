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

extern "C" void fn_102_CB90(Data *data, unsigned int value, float first, float second,
                            unsigned char byte0, unsigned char byte1,
                            unsigned char byte2, unsigned char byte3)
{
    data->value = value;
    data->first = first;
    data->second = second;
    data->byte0 = byte0;
    data->byte1 = byte1;
    data->byte2 = byte2;
    data->byte3 = byte3;
}
