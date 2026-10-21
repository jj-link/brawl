#include <types.h>
#pragma force_active on

extern "C" {

void fn_802ED860();
void fn_802EFF2C(void* arg0, s8* arg1);

struct Obj802ED81C {
    u8 pad_0x00[0x7C];
    void* field_0x7C;
};

struct Locals {
    s8 flag;
    s32 val;
};

void fn_802ED81C(Obj802ED81C* self, s32 arg1) {
    struct Locals locals;
    if (self->field_0x7C) {
        locals.val = arg1;
        locals.flag = 0xB;
        fn_802EFF2C(self, &locals.flag);
    } else {
        fn_802ED860();
    }
}

}
