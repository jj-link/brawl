#pragma force_active on
extern "C" void fn_76_10CC(void *p)
{
    unsigned char *flags = (unsigned char *)p + 0x6c;
    unsigned int value = *flags;
    value &= ~8u;
    *flags = (unsigned char)value;
}
