#include <types.h>
#pragma force_active on

extern "C" {
void fn_801D3C54(void** arg0) {
    void* temp_r4;

    temp_r4 = *arg0;
    if (temp_r4 != NULL && *(void***)((char*)temp_r4 + 0x1B0) == arg0) {
        *(void**)((char*)temp_r4 + 0x1B0) = NULL;
    }
    if (*arg0 != NULL) {
        *arg0 = NULL;
    }
}
}
