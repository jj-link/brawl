#pragma force_active on
extern "C" void fn_27_FE6D0(unsigned int *p)
{
    unsigned int value = p[2];
    value = (value & 0xFFF00000u) | (value & 0x0007FFFFu);
    p[2] = value;
}
