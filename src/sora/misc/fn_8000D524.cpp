#pragma force_active on
extern "C" unsigned short fn_8000D524(void *arg)
{
    return *(unsigned short *)((char *)*(void **)((char *)arg + 0x20) + 0x3c);
}
