#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Fn96_1D66CData
{
    u32 value;
    float first;
    float second;
    u8 byte0;
    u8 byte1;
    u8 byte2;
    u8 byte3;
};

extern "C" void fn_96_1D66C(
    Fn96_1D66CData *out,
    u32 value,
    float first,
    float second,
    u8 byte0,
    u8 byte1,
    u8 byte2,
    u8 byte3)
{
    out->value = value;
    out->first = first;
    out->second = second;
    out->byte0 = byte0;
    out->byte1 = byte1;
    out->byte2 = byte2;
    out->byte3 = byte3;
}
