#include <gm/gm_global.h>
#pragma force_active on

extern "C" void fn_80150494(int arg) {
    unsigned char* p = (unsigned char*)(*(unsigned int**)((unsigned char*)g_GameGlobal + 0x38)) + 8;
    unsigned char v = *p;
    *p = v | arg;
}
