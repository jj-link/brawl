#pragma force_active on
extern "C" int fn_96_1E2C4(const unsigned int* data)
{
    return static_cast<int>((data[2] << 8) & 0xF8000000U) >> 28;
}
