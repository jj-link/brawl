#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" int fn_96_1E328(const Data* data)
{
    return (int)((data->flags << 4) & 0xF8000000U) >> 28;
}
