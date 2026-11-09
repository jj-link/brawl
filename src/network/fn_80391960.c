#include <types.h>
#pragma force_active on

extern void *fn_80397564(void);
extern void *fn_80397578(void *);
extern void *fn_80397580(void *);
extern s32 fn_80397568(s32);
extern void fn_803900E4(void *, s32);
extern void fn_8039094C(void);
extern s32 fn_803906BC(void *, void *);
extern void fn_80390950(s32);
extern void fn_80390A58(s32);

s32 fn_80391960(void *arg0, void *arg1) {
    void *r31;
    s32 r30;
    s32 r29;
    s32 res;

    r31 = fn_80397564();
    r30 = (s32)fn_80397578(arg0);
    r29 = (s32)fn_80397580(arg0);
    if (*(s32 *)((char *)arg1 + 4) != 0) {
        fn_803900E4(r31, 0xb);
        return -1;
    }
    fn_8039094C();
    res = fn_803906BC((void *)fn_80397568((s32)arg0), arg1);
    if (res >= 0) {
        *(s32 *)((char *)arg1 + 4) = 1;
        fn_80390A58(r30);
    } else {
        fn_803900E4(r31, 1);
    }
    fn_80390950(r29);
    return res;
}
