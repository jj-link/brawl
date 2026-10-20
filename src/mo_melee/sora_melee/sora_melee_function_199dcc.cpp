#pragma force_active on
extern "C" void fn_27_199DCC(unsigned int *p, unsigned int value)
{
    p[2] = __rlwimi(p[2], value, 17, 10, 14);
}
