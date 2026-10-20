#pragma force_active on
extern "C" void fn_48_B888(unsigned int *p, unsigned int value)
{
    p[2] = __rlwimi(p[2], value, 25, 0, 6);
}
