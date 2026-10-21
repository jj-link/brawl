#pragma force_active on
extern "C" unsigned short fn_8015DAC0(void *arg)
{
    return *(unsigned short *)((char *)*(void **)((char *)arg + 0x10) + 0x8);
}
