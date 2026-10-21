#pragma force_active on
typedef unsigned short u16;

extern int fn_803B000C(void *, u16 *);

int fn_803B6F80(void *arg0, u16 *arg1)
{
    int result = 0;

    if ((*arg1 & 2) == 2) {
        result = fn_803B000C(arg0, arg1);
    }

    return result;
}
