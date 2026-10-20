#pragma force_active on
extern "C" int fn_40_1DEE0(const unsigned int* p)
{
    return static_cast<int>((p[2] << 6) & 0xFE000000u) >> 26;
}
