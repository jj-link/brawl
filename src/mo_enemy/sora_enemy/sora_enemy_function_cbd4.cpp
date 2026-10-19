#include <types.h>
#pragma force_active on

class emManager;

extern emManager* lbl_41_bss_30;

struct FnCD80Ret {
    u32 _0;
    u32 _4;
    u32 _8;
    u32 _C;
    u32 _10;
    u32 _14;
};

extern "C" {
FnCD80Ret* fn_41_CD80(emManager*, u32);
void fn_41_188(void*);
s32 fn_41_CB58(u32 kind, u32 arg);
void fn_41_CC44(s32* obj, u32 p2, s32 (*p3)(s32, s32));
void fn_41_C8D0(u8* self);

void fn_41_CBD4(emManager* mgr, u32 param2) {
    FnCD80Ret* r31 = fn_41_CD80(mgr, param2);
    if (r31 != nullptr && r31->_14 != 0) {
        fn_41_188((void*)r31->_14);
        s32 (*fp)(s32, s32) = (s32 (*)(s32, s32))&fn_41_CB58;
        fn_41_CC44((s32*)mgr, param2, fp);
        fn_41_C8D0((u8*)r31);
    }
}
}
