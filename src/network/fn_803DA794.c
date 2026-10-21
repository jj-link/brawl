#include <types.h>
#pragma force_active on

extern int fn_803D9D68(void *, void *, int, unsigned int);

int fn_803DA794(void *arg0, int arg1, unsigned int arg2) {
    char *base = (char *)arg0;
    int x;
    if (arg2 >= *(unsigned int *)(base + 8)) {
        return 0x10;
    }
    x = fn_803D9D68(arg0, base + 0x1630, arg1, arg2);
    x &= ((-x | x) >> 31);
    return x;
}
