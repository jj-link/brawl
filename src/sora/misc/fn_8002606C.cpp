#pragma force_active on
typedef unsigned int u32;
typedef int s32;
struct gfBlock {
    u32 unk0;
    u32 size;
    gfBlock* next;
};
struct gfBlockPool {
    u32 unk0;
    u32 unk4;
    gfBlock* first;
};
class gfMemoryPool {
public:
    u32 getMaxFreeBlockSize();
    char pad[0x20];
    gfBlockPool* m_pool;
};

extern "C" u32 getMaxFreeBlockSize__12gfMemoryPoolFv(gfMemoryPool* p) {
    u32 max = 0;
    gfBlock* node = p->m_pool->first;
    for (;;) {
        s32 v = (s32)(node->size - 0x20);
        u32 c = (u32)v & (u32)(~(s32)((s32)(v | ~(s32)(-v)) >> 31));
        if (max < c) max = c;
        gfBlock* next = node->next;
        if (node >= next) return max;
        node = next;
    }
}
