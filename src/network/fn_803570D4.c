#include <types.h>
#pragma force_active on

extern s32 lbl_805344C8[];
extern void (*lbl_805A1000)(void);
extern s32 lbl_805A1018;
extern s32 lbl_805A101C;
extern void (*lbl_805A1024)(s32);

void fn_803570D4(void) {
    s32 var_r30;
    s32 *var_r29;

    var_r30 = 0;
    var_r29 = lbl_805344C8;
    do {
        if (*var_r29 != 0) {
            lbl_805A1024(*var_r29);
            *var_r29 = 0;
        }
        var_r30 += 1;
        var_r29 += 1;
    } while (var_r30 < 3);
    lbl_805A1024(lbl_805A1018);
    lbl_805A1024(lbl_805A101C);
    lbl_805A1000();
}
