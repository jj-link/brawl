#include <types.h>
#pragma force_active on

typedef struct { void **items; s32 count; } ListObj;
extern void fn_8035AC70(void *, void (*)(void *, s32), s32);
void fn_8035B264(ListObj *self, void (*fn)(void *, s32), s32 arg)
{
    s32 i;
    for (i = 0; i < self->count; i++) {
        fn_8035AC70(self->items[i], fn, arg);
    }
}
