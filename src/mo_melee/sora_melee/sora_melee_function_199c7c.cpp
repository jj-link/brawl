#pragma force_active on
extern "C" int fn_27_199C7C(const unsigned int *p)
{
    int value = (int)((p[2] << 10) & 0xFC000000u);
    return value >> 27;
}
