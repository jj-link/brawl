#include <types.h>
#pragma force_active on

extern double __mffs(void);
#pragma optimization_level 0
u32 fn_801D50EC(void) {
    union { double d; u32 w[2]; } u;
    double fpscr;
    fpscr = __mffs();
    u.d = fpscr;
    return u.w[1];
}
