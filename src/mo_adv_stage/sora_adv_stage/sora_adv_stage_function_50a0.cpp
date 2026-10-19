#pragma force_active on
extern "C" void fn_40_50A0(const unsigned char* mgr, float* dst, int index)
{
    const float* src = *(const float* const*)(mgr + 0x584) + index * 2;
    dst[0] = src[0];
    dst[1] = src[1];
}
