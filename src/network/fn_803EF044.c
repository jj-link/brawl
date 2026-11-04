#include <types.h>
#pragma force_active on

typedef struct Owner {
    char pad[0x30];
    u32 count;
} Owner;

typedef struct Object {
    Owner* owner;
    char rest[12];
} Object;

extern int fn_801C8B20(Owner*);
extern void* fn_801C96A8(Owner*, int);
extern void fn_801CAD90(void*, int);
extern void fn_801CA7E8(void*);
extern void* fn_80072FD4(void*, int);
extern void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern void __dl__FPv(void*);
extern int lbl_805A12C8;

Object* fn_803EF044(Object* self, int flag) {
    u32 i;
    void* p;
    if (self) {
        if (fn_801C8B20(self->owner)) {
            for (i = 0; i < self->owner->count; i++) {
                fn_801CAD90(fn_801C96A8(self->owner, i), 0);
            }
        }
        self->owner = 0;
        lbl_805A12C8 = 0;
        __destroy_arr((char*)self + 8, (void (*)(void*, int))fn_80072FD4, 4, 2);
        p = (char*)self + 4;
        if (p) {
            fn_801CA7E8(p);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
