#include <string.h>
#pragma force_active on

int fn_80368990(void *arg0, void *arg1) {
    void *ptr;
    if (arg0 == 0 || (ptr = *(void **)arg0, ptr == 0)) {
        return 2;
    }
    memcpy(arg1, (char *)ptr + 0x48C, 0x19);
    return 0;
}
