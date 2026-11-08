#include <types.h>

#pragma force_active on

extern s32 fn_80335238(void);
extern int fn_8035661C(const char *arg0, const char *arg1, const char *arg2);

int fn_803560A4(const char *arg0, const char *arg1, const char *arg2) {
    if (fn_80335238() != 0) {
        return 0;
    }
    return fn_8035661C(arg0, arg1, arg2);
}
