#include "ec/ec_mgr.h"
#pragma force_active on

extern "C" u32 fn_8005F814(ecMgr* ptr, u32 effectID, u32 something, u32 a, u32 b, u32 c);

u32 ecMgr::setEffect(EfID effectID) {
    return fn_8005F814(this, effectID, effectID >> 16, 0, 0, 0);
}
