#include <types.h>
#pragma force_active on

class emManager;

extern emManager* lbl_41_bss_30;

struct FnCD80Ret {
    u32 _0;
    u32 _4;
    u32 _8;
};

extern "C" FnCD80Ret* fn_41_CD80(emManager*, u32);

extern "C" u32 fn_41_CB10(u32 a, u32 param1, u32 param2) {
    emManager* mgr = lbl_41_bss_30;
    FnCD80Ret* p = fn_41_CD80(mgr, param2);
    return static_cast<u32>(__cntlzw(param1 - p->_8)) >> 5;
}
