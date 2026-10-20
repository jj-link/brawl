#pragma force_active on
extern "C" void fn_27_199E88(unsigned int *object, unsigned int value)
{
    object[2] = __rlwimi(object[2], value, 28, 0, 3);
}
