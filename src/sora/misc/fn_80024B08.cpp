#pragma force_active on

class gfMemoryPool;

struct HeapInfo {
    const char* m_name;
    gfMemoryPool* m_memoryPool;
    unsigned int m_size;
    unsigned int m_arena;
};

extern HeapInfo g_HeapInfos[0x47];

class gfMemoryPool {
public:
    unsigned int getMaxFreeBlockSize();
};

class gfHeapManager {
public:
    static void dumpList();
};

extern "C" {
    extern char lbl_804224D8[];
    extern const float lbl_805A14E0;
    extern const float lbl_805A14F8;
    extern const float lbl_805A14FC;
    int fn_801D712C();
    int fn_801D7134();
    int fn_801D7144();
    int fn_801D714C();
    void OSReport(const char*, ...);
}

void gfHeapManager::dumpList() {
    char* base = lbl_804224D8;
    unsigned int size;
    HeapInfo* p;
    gfMemoryPool* pool;
    int arena;
    int mem1;
    int mem2;
    unsigned int sizeSum;
    unsigned int freeSum;
    int i;
    unsigned int freeSize;

    mem1 = fn_801D712C() - fn_801D7144();
    mem2 = fn_801D7134() - fn_801D714C();
    OSReport(base + 0x280);

    for (arena = 0; arena < 2; arena++) {
        sizeSum = 0;
        freeSum = 0;
        OSReport(base + 0x2C0, arena + 1);
        OSReport(base + 0x280);

        p = g_HeapInfos;
        for (i = 0; i < 0x47; i++, p++) {
            pool = p->m_memoryPool;
            if (pool != 0 && (unsigned int)arena == p->m_arena) {
                size = p->m_size;
                freeSize = size - pool->getMaxFreeBlockSize();
                int start = *(int*)((char*)pool + 4);
                int end = *(int*)((char*)pool + 8);
                float sizeMB = (float)size / lbl_805A14E0;
                float freeMB = (float)freeSize / lbl_805A14E0;
                OSReport(base + 0x300, i, p->m_name, start, end, end - start,
                         sizeMB, freeMB, lbl_805A14F8 * (freeMB / sizeMB));
                sizeSum += size;
                freeSum += freeSize;
            }
        }

        float totalMB = (float)sizeSum / lbl_805A14E0;
        float totalFreeMB = (float)freeSum / lbl_805A14E0;
        float availMB;
        if (arena != 0) {
            availMB = (float)mem2 / lbl_805A14E0;
        } else {
            availMB = (float)mem1 / lbl_805A14E0;
        }
        OSReport(base + 0x350, totalMB, totalFreeMB, lbl_805A14F8 * (totalFreeMB / totalMB));
        OSReport(base + 0x390, availMB);
        if (arena != 0) {
            float over = totalMB - availMB;
            if (over > lbl_805A14FC) {
                OSReport(base + 0x3BC, lbl_805A14FC - over);
            }
        }
        OSReport(base + 0x280);
    }
}
