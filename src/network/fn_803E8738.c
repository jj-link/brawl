#include <types.h>
#pragma force_active on

extern char lbl_805644C0[];
extern char lbl_8059FEFC;
extern char lbl_8059FF04;

extern void PF_enterCritical(void *p);
extern void PF_exitCritical(void *p);
extern char *fn_803D645C(char *dst, char *src);
extern s32 fn_803D6480(char *a, char *b);
extern u32 fn_803D66F4(void *p);
extern s32 fn_803D69AC(void *a, char *b);
extern char *fn_803D6528(void *a, void *b);
extern void fn_803E7C50(void *a, void *b);

void fn_803E8738(void *arg0, void *arg1, void *arg2) {
    s16 sp8[2];

    if (fn_803D66F4(arg2) == 1) {
        if (fn_803D6480(*(char **)arg2, &lbl_8059FF04) == 0) {
            fn_803D645C(arg0, &lbl_8059FEFC);
            return;
        }
        fn_803D645C(arg0, *(char **)arg2);
        return;
    }
    if (fn_803D69AC(arg2, &lbl_8059FF04) == 0) {
        sp8[0] = 0x2A;
        sp8[1] = 0;
        fn_803D6528(arg1, sp8);
    } else {
        fn_803D6528(arg1, *(char **)arg2);
    }
    if ((*(u32 *)(lbl_805644C0 + 0x60) & 2) == 2) {
        PF_enterCritical(lbl_805644C0 + 0x64);
        *(u32 *)(lbl_805644C0 + 0x60) = (*(u32 *)(lbl_805644C0 + 0x60) & ~3) | 1;
        fn_803E7C50(arg0, arg1);
        *(u32 *)(lbl_805644C0 + 0x60) = (*(u32 *)(lbl_805644C0 + 0x60) & ~3) | 2;
        PF_exitCritical(lbl_805644C0 + 0x64);
        return;
    }
    fn_803E7C50(arg0, arg1);
}
