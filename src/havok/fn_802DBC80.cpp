#include <types.h>
#pragma force_active on
struct Value { s32 value; };
extern "C" void fn_802DBD10(s32, Value*);

extern "C" void fn_802DBC80(s32 arg0) {
    Value value;
    value.value = 1;
    if (arg0 != 0) {
        Value copy = value;
        fn_802DBD10(arg0, &copy);
    }
}
