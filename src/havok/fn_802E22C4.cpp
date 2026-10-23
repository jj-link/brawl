#include <types.h>
#pragma force_active on

struct Value { s32 value; };

extern "C" void fn_802E1184(void*, Value*);
extern "C" char lbl_80487F10[0x20];

extern "C" void fn_802E22C4(void **arg0) {
    Value value;
    value.value = 1;
    if (arg0 != NULL) {
        Value copy = value;
        fn_802E1184(arg0, &copy);
        *arg0 = lbl_80487F10;
    }
}
