#include <internal/printf.h>
#pragma force_active on

extern int *fn_8035A598(int, int);
extern int fn_803822D8(int, const char *, int, int);
extern char lbl_8059FB48[7];
extern void *lbl_805A10B0;

static inline int resolve_index(void *obj, int index)
{
    if (obj == 0) {
        obj = lbl_805A10B0;
    }
    if (obj == 0) {
        return index;
    }
    return *fn_8035A598(((int *)obj)[8], index);
}

int fn_803851DC(void *arg0, const char *arg1, int (*arg2)(int, const char *, int), int arg3, int arg4) {
    char sp8[64];
    int ret;

    arg4 = resolve_index(arg0, arg4);
    sprintf(sp8, lbl_8059FB48, arg1, arg4);
    if (arg0 == 0) {
        arg0 = lbl_805A10B0;
    }
    if (arg0 == 0) {
        return arg3;
    }
    ret = arg2(((int *)arg0)[3], sp8, arg3);
    if (ret == 0) {
        ret = fn_803822D8(((int *)arg0)[3], sp8, 2, arg3);
    }
    return ret;
}
