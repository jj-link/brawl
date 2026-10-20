#pragma force_active on
extern "C" int fn_27_C8B50(const unsigned int* p)
{
    unsigned int x = p[1];
    unsigned int r = (x << 15) | (x >> 17);
    return (int)(r & 0xFC000000u) >> 27;
}
