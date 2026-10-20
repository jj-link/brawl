#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value;
};

extern "C" int fn_113_11E10(const Data* data)
{
    return (int)((data->value << 2) & 0xE0000000u) >> 30;
}
