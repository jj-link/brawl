#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" int fn_50_6308(const Data* data)
{
    return static_cast<int>((data->flags << 4) & 0xE0000000u) >> 30;
}
