#include <types.h>
#pragma force_active on

extern "C" void fn_803F0D4C(void* block, void* (*destroy)(void*, s32));
extern "C" void* fn_27_121268(void* p, s32 n);
extern void* g_ftSlotManager;

struct sora_melee_obj {
    void* m_block;
    s32 m_count;
};

extern "C" {
void* fn_27_1212A8(sora_melee_obj* p, s32 n) {
    if (p) {
        fn_803F0D4C(p->m_block, fn_27_121268);
        p->m_block = 0;
        p->m_count = 0;
        g_ftSlotManager = 0;
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
}
