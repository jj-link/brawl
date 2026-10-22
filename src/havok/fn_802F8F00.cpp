#include <types.h>
#pragma force_active on

struct Container {
    char pad[0x78];
    s32 field_78;
    s32 field_7c;
    char pad_80[4];
    s8 field_84;
};

extern "C" void fn_802F50E8();
extern "C" void fn_802F4068(void*, s32);
extern "C" void fn_802EFE70(void*);

extern "C" s32 fn_802F8F00(void* arg0, s32 arg1, s32 arg2) {
    Container* self = (Container*)arg0;
    self->field_7c++;
    fn_802F50E8();
    if (arg2 != 0) {
        fn_802F4068(arg0, arg1);
    }
    self->field_7c--;
    if (self->field_7c == 0 && self->field_78 != 0 && self->field_84 == 0) {
        fn_802EFE70(arg0);
    }
    return arg1;
}
