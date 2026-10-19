#include <types.h>
#pragma force_active on

struct fnA9168Obj {
    u8 pad[8];
    u8 counter;
};

extern "C" {
void reset__18gfGameFrameCounterFv(void*);
void start__18gfGameFrameCounterFv(void*);
}

extern "C" {
void fn_27_A9168(fnA9168Obj* self) {
    reset__18gfGameFrameCounterFv(&self->counter);
    start__18gfGameFrameCounterFv(&self->counter);
}
}
