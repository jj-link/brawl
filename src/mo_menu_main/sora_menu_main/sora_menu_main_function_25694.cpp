#include <types.h>
#pragma force_active on

extern "C" void* fn_8004E5D8(void*, void*);
extern void* g_GameGlobal;

extern "C" u16 fn_2_25694(void* arg) {
    void* p = fn_8004E5D8(g_GameGlobal, arg);
    return *reinterpret_cast<u16*>(static_cast<char*>(p) + 0x66);
}
