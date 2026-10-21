#pragma force_active on
extern "C" unsigned short fn_8015E0C8(void* arg)
{
    void* a = *(void**)((char*)arg + 0x14);
    void* b = *(void**)((char*)a + 0x8);
    return *(unsigned short*)((char*)b + 0x0a);
}
