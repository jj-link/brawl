#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1A4FD8(void* arg) {
    s32 val = *(s32*)((char*)arg + 8);
    return val >> 27;
}
