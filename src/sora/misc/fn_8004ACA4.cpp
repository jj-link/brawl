#include <types.h>
#pragma force_active on

extern "C" int fn_8004B5E4(int* arg0);

extern "C" int fn_8004ACA4(int* arg0) {
    int result = 0;
    if (arg0[6] != 0) {
        result = fn_8004B5E4((int*)arg0[6]);
    }
    return result;
}
