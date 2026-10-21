#pragma force_active on
extern "C" void fn_48_1FFC(void *p)
{
    unsigned char *c = (unsigned char *)p + 0x6c;
    *c = *c & ~0x08;
}
