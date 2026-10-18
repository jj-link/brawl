#include <types.h>
#pragma force_active on

extern "C" {
typedef int (*fn_ptr_t)(void*);

struct lbl_12_rodata_t {
    fn_ptr_t onEnter;
    fn_ptr_t update;
};

extern lbl_12_rodata_t lbl_12_rodata_0[];

extern void fn_800B9984(void* arg);

struct soraMenuGameState {
    unsigned char _0x00[0x44];
    int state;  // 0x44
    int last;   // 0x48
};

void fn_12_6C4(soraMenuGameState* self) {
    fn_800B9984((void*)((char*)self + 0x70));
    if (self->last != self->state) {
        fn_ptr_t onEnter = lbl_12_rodata_0[self->state].onEnter;
        if (onEnter) {
            onEnter(self);
        }
        self->last = self->state;
    }
    fn_ptr_t update = lbl_12_rodata_0[self->state].update;
    if (update) {
        self->state = update(self);
    }
}
}
