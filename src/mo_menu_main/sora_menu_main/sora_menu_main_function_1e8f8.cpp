#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E5D8(void*, void*);
extern "C" int isCharUsable__6muMenuFiii(int);

extern "C" u32 fn_2_1E8F8(u32 arg) {
    unsigned short* p = static_cast<unsigned short*>(fn_8004E5D8(g_GameGlobal, reinterpret_cast<void*>(arg)));
    int i;
    int sum = 0;
    for (i = 0; i < 35; i++) {
        if (isCharUsable__6muMenuFiii(i)) {
            sum += *p;
        }
        p++;
    }
    return sum;
}
