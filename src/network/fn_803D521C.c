#include <types.h>
#pragma force_active on
int fn_803D521C(void* arg0) {
    int var_r4;
    if (arg0 == NULL)
        return 0;
    var_r4 = 0;
    if (*(int*)arg0 != 0 || *(int*)((char*)arg0 + 4) != 0)
        var_r4 = 1;
    return var_r4;
}
