#include <snd/snd_system.h>
#pragma force_active on

extern "C" void fn_8007A79C(sndHeapSys*);
extern "C" void fn_80079B60(void*, int, int);

void sndSystem::freeGroup(int heapLevel, int p2) {
    if (heapLevel >= 0 && m_sndHeapSys != 0) {
        fn_8007A79C(m_sndHeapSys);
        fn_80079B60(*(void**)(_2D4 + 0x8C4), heapLevel, p2);
    }
}
