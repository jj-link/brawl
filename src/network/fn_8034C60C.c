#include <types.h>
#pragma force_active on

extern void fn_80335638(int level, const char *fmt, ...);
extern void fn_8034A1EC(s32);
extern const char lbl_8048CBE0[];
extern const char lbl_8059F1A8;

void fn_8034C60C(s32 arg0, s32 arg1) {
    fn_80335638(2, lbl_8048CBE0, arg0);
    fn_80335638(2, &lbl_8059F1A8, arg1);
    fn_8034A1EC(arg0);
}
