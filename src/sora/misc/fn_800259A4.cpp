#pragma force_active on
class gfMemoryPool;

extern "C" gfMemoryPool* fn_80025B78(void*, const char*, void*, unsigned long);

extern "C" gfMemoryPool* create__12gfMemoryPoolFPvUlPCc(void* heapAddr, unsigned long size,
                                                        const char* heapName)
{
    if (heapAddr == 0) {
        return (gfMemoryPool*)heapAddr;
    }
    return fn_80025B78(heapAddr, heapName, heapAddr, size);
}
