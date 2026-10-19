#pragma force_active on
struct Data
{
    unsigned char pad[0x6c];
    unsigned char value;
};

extern "C" int fn_73_33B0(Data *data)
{
    return (data->value >> 3) & 1;
}
