#include <types.h>
#pragma force_active on

struct Object {
    void* vtable;
    u16 field4;
    u16 field6;
    u32 field8;
    u32 fieldC;
    u32 field10;
    u32 field14;
};

extern "C" {
extern char lbl_80487A08[0x30];
void fn_802D95E4(void* self, u32 v);

void* fn_802DA52C(Object* self) {
    self->field6 = 1;
    self->vtable = lbl_80487A08;
    fn_802D95E4(&self->fieldC, self->field14);
    fn_802D95E4(&self->fieldC, (u32)self);
    return self;
}
}
