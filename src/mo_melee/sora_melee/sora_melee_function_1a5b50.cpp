#pragma force_active on
extern "C" void fn_27_1A5B50(void *object)
{
    unsigned int flags = *(unsigned int *)((char *)object + 8);
    *(unsigned int *)((char *)object + 8) = flags | 2;
}
