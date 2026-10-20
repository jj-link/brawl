#pragma force_active on
struct DonkeyData {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" int fn_50_63A0(const DonkeyData* data)
{
    return static_cast<int>((data->flags << 4) & 0xE0000000u) >> 30;
}
