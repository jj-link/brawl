#include <types.h>
#pragma force_active on

extern char* g_GameGlobal;

extern "C" void fn_8015B01C(void* unused, char* base, u8 val) {
    s32 off = *(s32*)(g_GameGlobal + 0x30);
    if (off == 0) {
        return;
    }
    *(u8*)(base + off + 0x4914) = val;
}
