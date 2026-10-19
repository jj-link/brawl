#include <stddef.h>
#pragma force_active on

typedef int s32;
typedef short s16;

extern "C" {
void fn_125_1B84(void* this_, s16 flag);
void __dl__FPv(void* ptr);

void* fn_125_1CA0(void* this_, s32 flag) {
    if (this_ != NULL) {
        s16 zero = 0;
        fn_125_1B84(this_, zero);
        if ((s16)flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
}
