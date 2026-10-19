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
extern "C" u32 fn_41_CB10(u32 a, u32 param1, u32 param2);

extern "C" s32 fn_41_CB58(u32 kind, u32 arg) {
    if (fn_41_CB10((u32)lbl_41_bss_30, kind, arg) == 1) {
        FnCD80Ret* entry = fn_41_CD80(lbl_41_bss_30, arg);
        if (entry == nullptr) {
            return 1;
        }
        entry->_8 = 0xFFFF;
    }
    return 1;
}
