#pragma force_active on
extern "C" {
void *fn_123_15024(void *p)
{
    return *(void **)((char *)*(void **)((char *)p + 0xd8) + 0x20);
}
}
