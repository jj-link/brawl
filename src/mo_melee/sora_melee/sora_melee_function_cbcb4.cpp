#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_CBCB4(void *ptr) {
    return *(s32 *)((unsigned char *)ptr + 8) >> 27;
}
