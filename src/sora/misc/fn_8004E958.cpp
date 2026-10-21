#pragma force_active on
extern "C" unsigned int fn_8004E958(void *ptr)
{
    void *p = *(void **)ptr;
    return !((unsigned char *)p)[0x0A];
}
