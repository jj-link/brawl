#include <types.h>
#pragma force_active on
struct Value { s32 value; };
extern "C" void fn_802E1184(int, Value*);

extern "C" void fn_802E0E40(int arg0) {
    Value value;
    value.value = 1;
    if (arg0 != 0) {
        Value copy = value;
        fn_802E1184(arg0, &copy);
    }
}
