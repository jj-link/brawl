#pragma force_active on
extern "C" void fn_27_19B328(void *ptr)
{
    unsigned int value = *(unsigned int *)((char *)ptr + 8);
    value |= 0x00010000u;
    *(unsigned int *)((char *)ptr + 8) = value;
}
