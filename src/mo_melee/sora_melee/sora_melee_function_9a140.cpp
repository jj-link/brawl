#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" u32 fn_80060F3C(ecMgr*);

extern "C" u32 fn_27_9A140() {
    return fn_80060F3C(g_ecMgr);
}
