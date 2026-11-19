#include <types.h>

#pragma force_active on

extern "C" {
void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
void* __construct_new_array(void*, void (*)(), void*, unsigned long, int);
void* memset(void*, int, unsigned long);
void fn_27_2282B0(void);
}

struct Head {
    int w[0x17];
};

struct Elem {
    Head head;
    unsigned int m5C;
    int m60;
};

struct Owner {
    unsigned char pad0[4];
    Elem* arr;
};
struct OtherOwner {
    unsigned int pad0;
    Elem* arr;
};

extern "C" void fn_27_2282B4(Owner* self, Elem* src) {
    unsigned char idx;
    unsigned char found;
    if (self->arr == 0) {
        self->arr = (Elem*)__construct_new_array(__nwa__FUlQ25Heaps8HeapType(0x13C, 15), fn_27_2282B0, 0, 0x64, 3);
        memset(self->arr, 0, 0x12C);
        self->arr[0].m5C = 1;
        self->arr[1].m5C = 2;
        self->arr[2].m5C = 3;
    }
    if (src->m5C == self->arr[0].m5C) {
        idx = 0;
        found = 1;
    } else if (src->m5C == self->arr[1].m5C) {
        idx = 1;
        found = 1;
    } else if (src->m5C == self->arr[2].m5C) {
        idx = 2;
        found = 1;
    } else {
        found = 0;
    }
    if (found == 1) {
        Elem* dst = &((OtherOwner*)self)->arr[idx];
        dst->head = src->head;
        dst->m5C = src->m5C;
        dst->m60 = src->m60;
    }
}