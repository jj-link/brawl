#include <stddef.h>
#pragma force_active on

extern "C" {
void* fn_110_408C(void*, short);
void* fn_110_6984(void*, short);
void* fn_27_CD934(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_110_690C(void* object, short deleting) {
    if (object != 0) {
        fn_110_408C(static_cast<unsigned char*>(object) + 0xAC, -1);
        fn_110_6984(static_cast<unsigned char*>(object) + 0x20, -1);
        fn_27_CD934(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
