#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_93100(void*, short);
void* fn_102_31C0(void*, short);
void* fn_27_19F4C4(void*, short);
void* fn_27_1A55B0(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_102_3138(char* obj, short deleting) {
    if (obj != 0) {
        short memberDeleting = -1;
        fn_27_93100(obj + 0x10000 - 0x4240, memberDeleting);
        fn_102_31C0(obj + 0x7c, memberDeleting);
        fn_27_19F4C4(obj + 0x20, memberDeleting);
        fn_27_1A55B0(obj, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
