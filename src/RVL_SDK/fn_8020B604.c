#include <revolution/types.h>
#pragma force_active on

extern s32 fn_8020CAD4(void);
extern s32 fn_8020B3D8(s32, s32, void *, s32, s32);
extern s32 fn_8020CAEC(void);

s32 fn_8020B604(s32 arg0, s32 arg1) {
    if (fn_8020CAD4() != 0) {
        fn_8020B3D8(arg0, arg1, 0, 0, 1);
        return fn_8020CAEC();
    }
    return -0x80;
}
