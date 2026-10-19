#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E5D8(void*, void*);

extern "C" unsigned short fn_2_25634(unsigned int arg) {
    unsigned short* p = static_cast<unsigned short*>(fn_8004E5D8(g_GameGlobal, reinterpret_cast<void*>(arg)));
    return p[0x64 / 2];
}
