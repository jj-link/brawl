#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value;
};

extern "C" int fn_40_11580(const Data* data)
{
    return static_cast<int>((data->value << 10) & 0xFC000000u) >> 27;
}
