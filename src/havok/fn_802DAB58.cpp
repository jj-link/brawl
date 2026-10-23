#include <types.h>
#pragma force_active on

struct Value { s32 value; };

extern "C" void fn_802DABE8(s32, Value*);

extern "C" void fn_802DAB58(s32 arg0) {
    Value value;
    value.value = 1;
    if (arg0 != 0) {
        Value copy = value;
        fn_802DABE8(arg0, &copy);
    }
}
