#include <gm/gm_global.h>
#pragma force_active on

extern "C" void fn_8014FEC8(int arg0, int arg1) {
    int* p = *(int**)((char*)g_GameGlobal + 0x38);
    p[1] = arg1;
    p[0] = arg0;
}
