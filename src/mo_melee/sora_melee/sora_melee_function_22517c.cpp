#include <types.h>
#pragma force_active on

namespace Heaps {
enum HeapType { HEAP_DEFAULT = 0 };
}

namespace StSeUtil {
struct UnkStruct;

class SeSeq {
public:
    struct Entry {
        UnkStruct* m_unk;
        u32 m_size;
        void* m_ptr;
    };

    void registSeq(int idx, UnkStruct* unk, u32 n, Heaps::HeapType heap);

    u32 m_pad;
    Entry* m_entries;
    u32 m_count;
};
}

extern "C" void fn_27_22520C(void* self);
extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long size, Heaps::HeapType heap);

namespace StSeUtil {
void SeSeq::registSeq(int idx, UnkStruct* unk, u32 n, Heaps::HeapType heap) {
    if (idx >= 0 && (u32)idx < m_count) {
        Entry* e = &m_entries[idx];
        void* p = __nwa__FUlQ25Heaps8HeapType(n * 4, heap);
        e->m_ptr = p;
        if (p != nullptr) {
            e->m_unk = unk;
            e->m_size = n;
        }
    }
    fn_27_22520C(this);
}
}
