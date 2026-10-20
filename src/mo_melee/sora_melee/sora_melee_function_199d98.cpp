#pragma force_active on
extern "C" void fn_27_199D98(unsigned int *p)
{
    unsigned int value = p[2];
    value &= ~(1u << 16);
    p[2] = value;
}
