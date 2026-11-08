#include <gf/gf_memory_pool.h>
#pragma force_active on

extern "C" {
extern u8 lbl_805A0000;

void fn_800242DC(void) {
    int i;
    for (i = 0; i < 0x40; i += 16) {
        HeapInfo* p = &g_HeapInfos[i];
        p[0].m_name = 0;
        p[0].m_memoryPool = 0;
        p[0].m_size = 0;
        p[1].m_name = 0;
        p[1].m_memoryPool = 0;
        p[1].m_size = 0;
        p[2].m_name = 0;
        p[2].m_memoryPool = 0;
        p[2].m_size = 0;
        p[3].m_name = 0;
        p[3].m_memoryPool = 0;
        p[3].m_size = 0;
        p[4].m_name = 0;
        p[4].m_memoryPool = 0;
        p[4].m_size = 0;
        p[5].m_name = 0;
        p[5].m_memoryPool = 0;
        p[5].m_size = 0;
        p[6].m_name = 0;
        p[6].m_memoryPool = 0;
        p[6].m_size = 0;
        p[7].m_name = 0;
        p[7].m_memoryPool = 0;
        p[7].m_size = 0;
        p[8].m_name = 0;
        p[8].m_memoryPool = 0;
        p[8].m_size = 0;
        p[9].m_name = 0;
        p[9].m_memoryPool = 0;
        p[9].m_size = 0;
        p[10].m_name = 0;
        p[10].m_memoryPool = 0;
        p[10].m_size = 0;
        p[11].m_name = 0;
        p[11].m_memoryPool = 0;
        p[11].m_size = 0;
        p[12].m_name = 0;
        p[12].m_memoryPool = 0;
        p[12].m_size = 0;
        p[13].m_name = 0;
        p[13].m_memoryPool = 0;
        p[13].m_size = 0;
        p[14].m_name = 0;
        p[14].m_memoryPool = 0;
        p[14].m_size = 0;
        p[15].m_name = 0;
        p[15].m_memoryPool = 0;
        p[15].m_size = 0;
    }
    HeapInfo* q = &g_HeapInfos[i];
    q[0].m_name = 0;
    q[0].m_memoryPool = 0;
    q[0].m_size = 0;
    q[1].m_name = 0;
    q[1].m_memoryPool = 0;
    q[1].m_size = 0;
    q[2].m_name = 0;
    q[2].m_memoryPool = 0;
    q[2].m_size = 0;
    q[3].m_name = 0;
    q[3].m_memoryPool = 0;
    q[3].m_size = 0;
    q[4].m_name = 0;
    q[4].m_memoryPool = 0;
    q[4].m_size = 0;
    q[5].m_name = 0;
    q[5].m_memoryPool = 0;
    q[5].m_size = 0;
    q[6].m_name = 0;
    q[6].m_memoryPool = 0;
    q[6].m_size = 0;
    lbl_805A0000 = 1;
}
}
