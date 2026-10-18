#pragma force_active on
extern "C" unsigned int fn_27_14D530(unsigned int x)
{
    unsigned int r3 = 1;
    unsigned int r4 = x - 77;
    r3 = r3 | ~r4;
    unsigned int r0 = (1 - r4) >> 1;
    return (r3 - r0) >> 31;
}
