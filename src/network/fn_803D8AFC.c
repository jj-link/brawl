#include <types.h>
#pragma force_active on

extern s32 fn_803D7B04(void *, void *);
extern s32 fn_803D7D28(void *, s32);

s32 fn_803D8AFC(void *self, s32 arg) {
    s32 result = fn_803D7B04(*(void **)((char *)self + 4), self);

    if (result != 0) {
        return result;
    }

    result = fn_803D7D28(*(void **)((char *)self + 4), arg);
    return result & ((-result | result) >> 31);
}
