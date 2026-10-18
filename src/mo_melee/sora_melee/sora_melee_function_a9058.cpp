#include <types.h>
#pragma force_active on

extern "C" {
void reset__18gfGameFrameCounterFv(void*);
void start__18gfGameFrameCounterFv(void*);
extern u32 lbl_27_data_15938[];
}

struct soTargetSearchUnit {
    u32* vtable;
    u32 unk4;
    s32 counter;
    u32 unkC;
    u32 unk10;
};

extern "C" soTargetSearchUnit* __ct__18soTargetSearchUnitFv(soTargetSearchUnit* self) {
    self->vtable = lbl_27_data_15938;
    self->unk4 = 0;
    self->counter = -1;
    self->unkC = 0;
    self->unk10 = 0;
    reset__18gfGameFrameCounterFv(&self->counter);
    start__18gfGameFrameCounterFv(&self->counter);
    return self;
}
