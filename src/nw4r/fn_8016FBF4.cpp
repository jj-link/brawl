#include <types.h>
#include <stddef.h>
#pragma force_active on

extern "C" void* fn_8016FBF4(void* arg0) {
    u8* p = *(u8**)((u8*)arg0 + 4);
    s32 flag;

    if (p == NULL) {
        flag = 0;
    } else {
        flag = (*(u32*)arg0 == *(u32*)(p + 8));
    }

    if (flag != 0) {
        return p;
    }
    return NULL;
}
