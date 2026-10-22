#include <types.h>
#pragma force_active on
struct Value { s32 value; };
extern "C" void fn_802F031C(s32, Value*);
extern "C" void fn_802F004C(s32 arg0) {
    Value value;
    value.value = 1;
    if (arg0 != 0) {
        Value copy = value;
        fn_802F031C(arg0, &copy);
    }
}
