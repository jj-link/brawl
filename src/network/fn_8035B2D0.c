#include <types.h>
#pragma force_active on

typedef struct {
    void **items;
    s32 count;
} ListObj;

extern s32 fn_8035AD0C(void *a, s32 b, s32 c);

s32 fn_8035B2D0(ListObj *self, s32 arg1, s32 arg2)
{
    s32 i;
    s32 r;

    for (i = 0; i < self->count; i++) {
        r = fn_8035AD0C(self->items[i], arg1, arg2);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}
