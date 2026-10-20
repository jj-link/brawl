#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" int fn_63_B22C(const Data* data)
{
    return static_cast<int>((data->flags << 8) & 0xF8000000u) >> 28;
}
