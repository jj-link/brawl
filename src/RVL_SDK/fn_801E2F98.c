#include <types.h>
#pragma force_active on

s32 fn_8020CDB8(void);
void fn_801E2AE8(s32, s32);
extern s32 lbl_8059EA00;
extern s32 lbl_805A0730;
extern s32 lbl_805A0734;
extern s32 lbl_805A0738;
extern s32 lbl_805A073C;
extern s32 lbl_805A0740;
extern s32 lbl_805A0744;

void fn_801E2F98(void) {
    if (fn_8020CDB8() == 0) {
        lbl_805A0738 = 0;
        lbl_805A0730 = 0;
        lbl_8059EA00 = 0;
        lbl_805A0734 = 0;
        lbl_805A0740 = 0;
        lbl_805A073C = 0;
        lbl_805A0744 = 0;
        fn_801E2AE8(0, 0);
    }
}
