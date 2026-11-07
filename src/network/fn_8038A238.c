#include <types.h>
#pragma force_active on

extern void *fn_80388590(s32);
extern s32 *fn_8035B1C4(void *, s32 *);
extern void fn_8035B120(void *, s32 *);

void fn_8038A238(s32 arg0, s32 arg1) {
    s32 *p;
    p = fn_8035B1C4(fn_80388590(arg0), &arg1);
    if (p != 0) {
        if (--p[1] == 0) {
            fn_8035B120(fn_80388590(arg0), &arg1);
        }
    }
}
