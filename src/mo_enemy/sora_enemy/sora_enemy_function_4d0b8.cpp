#pragma force_active on
#include <types.h>

extern "C" {

void* fn_41_4D048(void*, short);
void* fn_27_CB4A0(void*, short);
void* fn_41_2A480(void*, short);
void* __dt__18emTargetSearchUnitFv(void*, short);
void* fn_27_CB048(void*, short);
void* fn_27_CF608(void*, short);
void* fn_41_2CBC(void*, short);
void __destroy_arr(void*, void* (*)(void*, short), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_41_4D0B8(void* this_, short deleting) {
    if (this_) {
        char* members = static_cast<char*>(this_);
        short v = -1;
        fn_41_4D048(members + 0x5BDC, v);
        fn_27_CB4A0(members + 0x5B8C, v);
        __destroy_arr(members + 0x5AFC, fn_41_2A480, 8, 0x12);
        __destroy_arr(members + 0x5ACC, __dt__18emTargetSearchUnitFv, 0x18, 2);
        fn_27_CB048(members + 0x585C, v);
        fn_27_CF608(members + 0x5310, v);
        fn_41_2CBC(this_, static_cast<short>(0));
        if (deleting > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

}
