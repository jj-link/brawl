#include <types.h>
#pragma force_active on

extern "C" {

void fn_80203CF8(s32 arg0, s32 arg1);
void fn_80203CEC(s32 arg0, s32 arg1);
extern s32 lbl_805A0570;
void fn_801BBC98();
void fn_801BBCF8();

void fn_801BBC1C(s32 arg0, s32 arg1, s32 arg2) {
    fn_80203CF8(arg1, arg2);
    fn_80203CEC((s32)&fn_801BBC98, (s32)&fn_801BBCF8);
    lbl_805A0570 = arg0;
}

}
