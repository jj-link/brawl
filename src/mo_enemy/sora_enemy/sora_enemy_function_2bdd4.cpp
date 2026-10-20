#pragma force_active on
struct Fn41_2BDD4Data
{
    unsigned char padding[0x64];
    short value;
};

extern "C" bool fn_41_2BDD4(Fn41_2BDD4Data* data)
{
    return data->value >= 0;
}
