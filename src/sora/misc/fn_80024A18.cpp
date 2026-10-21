#pragma force_active on
// main/memory.c

typedef unsigned int u32;

class gfMemoryPool;

struct HeapInfo {
    const char* m_name;
    gfMemoryPool* m_memoryPool;
    u32 m_size;
    u32 m_arena;
};
extern HeapInfo g_HeapInfos[0x47];

extern "C" void* fn_80025EDC(gfMemoryPool*, int, u32);

extern "C" void* fn_80024A18(int heapID, int arg1) {
    return fn_80025EDC(g_HeapInfos[heapID].m_memoryPool, arg1, 0x20);
}
