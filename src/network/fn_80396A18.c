#include <types.h>
#pragma force_active on

extern void *fn_803974FC(void);
extern void *fn_80397580(void *);
extern void *fn_803970E4(void *, s32);

s32 fn_80396A18(s32 arg0, s32 arg1) {
    void *context;
    char *p;

    context = fn_80397580(fn_803974FC());
    p = fn_803970E4(context, arg0);
    if (p == 0) {
        return -1;
    }
    *(s32 *)(p + 0xcc) = arg1;
    return 0;
}
