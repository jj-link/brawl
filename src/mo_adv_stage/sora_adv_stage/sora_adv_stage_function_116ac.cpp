#pragma force_active on

extern "C" int fn_40_116AC(const unsigned int* arg0)
{
    unsigned int v = arg0[2];
    return (int)((v << 5) & 0xFC000000u) >> 27;
}
