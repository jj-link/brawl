#pragma force_active on
struct Data {
    unsigned char padding[8];
    int value;
};

extern "C" int fn_68_63D4(const Data* data)
{
    return data->value >> 30;
}
