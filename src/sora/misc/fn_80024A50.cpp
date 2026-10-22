#pragma force_active on

class gfMemoryPool;

struct HeapInfo {
    const char* m_name;
    gfMemoryPool* m_memoryPool;
    unsigned int m_size;
    unsigned int m_arena;
};

extern HeapInfo g_HeapInfos[0x47];

class gfHeapManager {
public:
    static void dumpAll();
};

extern "C" {
    extern char lbl_804224D8[];
    void fn_800260B4(void*);
    void OSReport(const char*, ...);
}

void gfHeapManager::dumpAll()
{
    char* base = lbl_804224D8;
    HeapInfo* p;
    gfMemoryPool* pool;
    int total;
    int i;
    total = 0;
    OSReport(base + 0x1EC);
    OSReport(base + 0x228);
    OSReport(base + 0x1EC);
    p = g_HeapInfos;
    i = 0;
    do {
        pool = p->m_memoryPool;
        if (pool != 0) {
            fn_800260B4(pool);
            total += *(int*)((char*)pool + 8) - *(int*)((char*)pool + 4);
        }
        i++;
        p++;
    } while (i < 0x47);
    OSReport(base + 0x268, total);
    OSReport(base + 0x1EC);
}
