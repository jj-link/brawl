#include <types.h>
#pragma force_active on

extern int fn_803D9E7C(int, int, int, unsigned int, int, int);

int fn_803DA7E4(int arg0, int arg1, unsigned int arg2, int arg3, int arg4) {
    int result;

    if (arg2 >= *(unsigned int *)(*(int *)&arg0 + 8)) {
        return 0x10;
    }
    result = fn_803D9E7C(arg0, *(int *)&arg0 + 0x1634, arg1, arg2, arg3, arg4);
    return result & ((-result | result) >> 31);
}