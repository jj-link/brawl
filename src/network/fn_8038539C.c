#pragma force_active on
#include <stl/internal/printf.h>

extern int *fn_8035A598(int, int);
extern double *fn_803822D8(int, const char *, int, double *);
extern char lbl_8059FB50[6];
extern void *lbl_805A10B0;

static inline int resolve_index(void *obj, int index)
{
    if (obj == 0) {
        obj = lbl_805A10B0;
    }
    if (obj == 0) {
        return index;
    }
    return *fn_8035A598(*(int *)((char *)obj + 0x1C), index);
}

double fn_8038539C(void *arg0, const char *arg1,
                   double *(*arg2)(int, const char *, double *),
                   int arg3, double farg0)
{
    char buffer[64];
    double value;
    double *result;

    arg3 = resolve_index(arg0, arg3);
    sprintf(buffer, lbl_8059FB50, arg1, arg3);
    value = farg0;
    if (arg0 == 0) {
        arg0 = lbl_805A10B0;
    }
    if (arg0 == 0) {
        result = &value;
    } else {
        result = arg2(*(int *)((char *)arg0 + 0xC), buffer, &value);
        if (result == 0) {
            result = fn_803822D8(*(int *)((char *)arg0 + 0xC), buffer, 1, &value);
        }
    }
    return *result;
}
