#pragma force_active on
struct Data {
    unsigned int unknown0;
    unsigned int unknown4;
    unsigned int flags;
};

extern "C" int fn_27_1CFE0C(const Data* data)
{
    return (int)((data->flags << 4) & 0xF8000000u) >> 28;
}
