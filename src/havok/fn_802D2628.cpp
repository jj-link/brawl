#include <types.h>
#pragma force_active on

struct Value { s32 value; };

extern "C" void __ct__14Class_802D279CFv(s32 arg0, Value* arg1);

extern "C" void fn_802D2628(s32 arg0) {
    Value value;
    value.value = 1;
    if (arg0 != 0) {
        Value copy = value;
        __ct__14Class_802D279CFv(arg0, &copy);
    }
}
