#include <gm/gm_global.h>
#pragma force_active on

extern "C" int fn_8014FDB0() {
    unsigned int sub = *(unsigned int*)((char*)g_GameGlobal + 0x38);
    return (*(unsigned short*)(sub + 0x0a) >> 5) & 1;
}
