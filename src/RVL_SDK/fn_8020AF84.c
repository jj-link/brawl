#include <types.h>
#pragma force_active on

extern s32 fn_8020CAD4(void);
extern s32 fn_8020AE58(s32, s32, s32, s32, s32, s32);
extern s32 fn_8020CAEC(void);

s32 fn_8020AF84(s32 arg0, s32 arg1, s32 arg2) {
    if (fn_8020CAD4() != 0) {
        fn_8020AE58(arg0, arg1, arg2, 0, 0, 0);
        return fn_8020CAEC();
    }
    return -0x80;
}