#pragma force_active on
extern "C" int fn_27_19BC18(const unsigned int* p)
{
    unsigned int value = p[2];
    value = (value << 5) & 0xFC000000u;
    return static_cast<int>(value) >> 27;
}
