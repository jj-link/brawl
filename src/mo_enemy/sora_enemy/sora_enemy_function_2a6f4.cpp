#pragma force_active on
extern "C" int fn_41_2A6F4(unsigned int flags, int bit)
{
    unsigned int mask = 1u << bit;
    return (mask & flags) != 0;
}
