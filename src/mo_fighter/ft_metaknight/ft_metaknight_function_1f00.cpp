#include <types.h>
#pragma force_active on

extern "C" void fn_111_1F84(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void fn_111_283C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_111_1F00(void* this_ptr, short destroy) {
    if (this_ptr != 0) {
        fn_111_1F84(static_cast<u8*>(this_ptr) + 0x88D8, -1);
        fn_27_C74E8(static_cast<u8*>(this_ptr) + 0x88C8, -1);
        fn_111_283C(this_ptr, 0);
        if (destroy > 0) __dl__FPv(this_ptr);
    }
    return this_ptr;
}
