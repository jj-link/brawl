#include <types.h>
#pragma force_active on

extern "C" void* g_GameGlobal;
extern "C" u32 fn_80056780();

extern "C" int fn_800527D8() {
    u32 idx = fn_80056780();
    void* record = *(void**)((char*)g_GameGlobal + 0x24);
    u16 val = *(u16*)((char*)record + idx * 2 + 0x842);
    return (val >> 14) & 1;
}
