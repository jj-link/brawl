#include <types.h>
#pragma force_active on

extern s32 fn_803D5EC8(void* p);
extern void fn_803D0250(void* a0, void* p, void* a4, void* a5, void* a6);

s32 fn_803D01E4(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6) {
    char buf[72];
    s32 ret = fn_803D5EC8(buf);
    if (ret == 0) {
        fn_803D0250(a0, buf, a4, a5, a6);
    }
    return ret;
}
