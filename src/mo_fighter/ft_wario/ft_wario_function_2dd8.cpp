#include <stddef.h>
#pragma force_active on

extern "C" {

extern void* fn_27_BED74(void*, short);
extern void __dl__FPv(void*);

void* fn_110_2DD8(void* this_ptr, short arg2) {
    if (this_ptr != 0) {
        fn_27_BED74(this_ptr, static_cast<short>(-1));
        if (arg2 > 0) {
            __dl__FPv(this_ptr);
        }
    }
    return this_ptr;
}

}
