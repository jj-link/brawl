#include <types.h>
#pragma force_active on

extern "C" void fn_27_B4698(void* self);
extern "C" char lbl_27_data_16D78[];

struct SoObj27 {
    void* vt0;
    void* vt1;
    u32 pad8;
    u32 padC;
    u32 pad10;
    u32 pad14;
    u32 f18;
    u32 f1C;
    u32 f20;
};

extern "C" {
SoObj27* fn_27_B215C(SoObj27* self, void* unused, u32 a, u32 b, u32 c) {
    fn_27_B4698(self);
    self->vt0 = lbl_27_data_16D78;
    self->vt1 = lbl_27_data_16D78 + 0xE0;
    self->f18 = a;
    self->f1C = b;
    self->f20 = c;
    return self;
}
}
