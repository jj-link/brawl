#pragma force_active on
extern "C" void fn_27_CD850(unsigned int *p)
{
    unsigned int value = p[2];
    value &= ~0x02000000u;
    p[2] = value;
}
