#pragma force_active on
extern "C" void fn_27_FDF94(int* dst, int* src, int value, const short* half, short half_value)
{
    dst[0] = *src;
    dst[1] = value;
    reinterpret_cast<short*>(dst)[4] = *half;
    reinterpret_cast<short*>(dst)[5] = half_value;
}
