#include <ec/ec_mgr.h>
#pragma force_active on
extern "C" int fn_80014348(void*, unsigned int, int*);
extern "C" int fn_80060FC4(ecMgr*, int);

extern "C" int fn_8001440C(void* self) {
    int result;
    unsigned int i = 0;
    for (;;) {
        if (!fn_80014348(self, i, &result))
            break;
        if (fn_80060FC4(g_ecMgr, result))
            return 1;
        ++i;
    }
    return 0;
}