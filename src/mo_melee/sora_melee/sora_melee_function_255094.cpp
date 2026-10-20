#include <types.h>
#pragma force_active on

class ipSwitch;
extern "C" {
void* getInstance__8ipSwitchFv();
void fn_8004A914(void*, int);
extern unsigned int lbl_27_bss_59C0;
void fn_27_254CDC(void (*)(void*));
void fn_27_254CE8(void (*)(void*));
void fn_27_254A74(void* self);
void fn_27_254A9C(void* self);
}

struct SoraSelf {
    char pad[0x49];
    u8 b49;
};

extern "C" void fn_27_255094(SoraSelf* self) {
    if (self->b49 != 0) {
        fn_8004A914(getInstance__8ipSwitchFv(), 1);
        lbl_27_bss_59C0 = (unsigned int)self;
        fn_27_254CDC(fn_27_254A74);
        fn_27_254CE8(fn_27_254A9C);
    }
}
