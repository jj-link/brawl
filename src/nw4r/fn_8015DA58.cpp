#pragma force_active on
extern "C" unsigned short fn_8015DA58(void *arg0)
{
    void *ptr = *(void **)((char *)arg0 + 0x10);
    return *(unsigned short *)((char *)ptr + 0xc);
}
