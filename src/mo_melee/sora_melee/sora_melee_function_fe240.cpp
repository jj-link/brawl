#pragma force_active on
extern "C" void fn_27_FE240(unsigned int *p, unsigned int value)
{
    unsigned int *field = p + 2;
    *field = __rlwimi(*field, value, 20, 6, 11);
}
