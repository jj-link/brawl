#include <types.h>
#pragma force_active on

extern void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern void fn_803EF038(void*);
extern void fn_80072FD4(void*, int);
extern int lbl_805A12C8;

typedef struct Obj {
    u32 unk0;
    u32 unk4;
    u8 arr[0x31];
    u8 unk39;
    u8 unk3A;
} Obj;

void* fn_803EEFCC(void* arg0) {
    Obj* self = (Obj*)arg0;
    self->unk4 = 0;
    __construct_array(self->arr, (void (*)(void*))fn_803EF038, (void (*)(void*))fn_80072FD4, 4, 2);
    self->unk39 = 0;
    self->unk3A = 0;
    lbl_805A12C8 = (int)self;
    self->unk0 = 0;
    return self;
}
