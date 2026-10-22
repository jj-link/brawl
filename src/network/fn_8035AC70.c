#include <types.h>
#pragma force_active on

typedef struct Obj {
    s32 count;
    char pad0[4];
    s32 stride;
    char pad1[8];
    char* base;
} Obj;

void fn_8035AC70(Obj* self, void (*fn)(void*, s32), s32 arg) {
    s32 i;

    for (i = self->count - 1; i >= 0; i--) {
        void* p;
        if (i < 0 || i >= self->count) {
            p = 0;
        } else {
            p = self->base + self->stride * i;
        }
        fn(p, arg);
    }
}
