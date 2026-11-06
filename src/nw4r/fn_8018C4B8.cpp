#include <types.h>
#pragma force_active on

extern "C" {
void fn_801EFB10(void);
void fn_801EF280(s32 a, s32 b);
void fn_801EFB44(s32 a, s32 b, s32 c, s32 d, s32 e);

void fn_8018C4B8(s32 arg0, s32 arg1) {
    s32 i;
    fn_801EFB10();
    fn_801EF280(9, 1);
    if (arg0 != 0) {
        fn_801EF280(11, 1);
    }
    for (i = 0; i < arg1; i++) {
        fn_801EF280(i + 13, 1);
    }
    fn_801EFB44(0, 9, 0, 4, 0);
    if (arg0 != 0) {
        fn_801EFB44(0, 11, 1, 5, 0);
    }
    for (i = 0; i < arg1; i++) {
        fn_801EFB44(0, i + 13, 1, 4, 0);
    }
}
}
