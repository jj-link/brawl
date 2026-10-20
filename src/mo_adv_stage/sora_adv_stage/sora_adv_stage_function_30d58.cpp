#pragma force_active on
extern "C" void fn_40_30D58(unsigned int *p)
{
    unsigned int *flags = p + 2;
    *flags &= 0xFFFEFFFF;
}
