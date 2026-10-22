#include <types.h>
#pragma force_active on

typedef struct Arr {
    s32 count;
    char pad4[4];
    s32 stride;
    char pad0c[8];
    void *base;
} Arr;

void *fn_8035AD0C(Arr *arr, s32 (*fn)(void *, s32), s32 arg) {
    void *p;
    s32 i;

    for (i = arr->count - 1; i >= 0; i--) {
        if (i < 0 || i >= arr->count) {
            p = 0;
        } else {
            p = (char *)arr->base + arr->stride * i;
        }
        if (fn(p, arg) == 0) {
            return p;
        }
    }
    return 0;
}
