#pragma force_active on
extern "C" int fn_27_CA8CC(const unsigned int* p)
{
    return (int)((p[2] << 10) & 0xFC000000u) >> 27;
}
