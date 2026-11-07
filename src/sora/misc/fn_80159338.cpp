#pragma force_active on

#include <string.h>
#include <gm/gm_global.h>

extern "C" void fn_80159338(void* self) {
    void** p = reinterpret_cast<void**>(self);
    memset(p[0], 0, 0x80);
    memcpy(p[1], reinterpret_cast<char*>(g_GameGlobal->m_advData) + 0x650, 0x80);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x10) = 0;
    memset(p[3], 0, 0x6300);
}