#include <gf/gf_memory_pool.h>
#pragma force_active on

extern "C" void fn_800244A0(int heapID) {
    g_HeapInfos[heapID].m_name = nullptr;
    g_HeapInfos[heapID].m_memoryPool = nullptr;
    g_HeapInfos[heapID].m_size = 0;
}
