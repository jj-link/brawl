#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_93100(void*, short);
void* fn_117_3290(void*, short);
void* fn_27_19F194(void*, short);
void* fn_27_1A52A4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_117_3208(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short destroy = -1;
        fn_27_93100(members + 0x3EFC4, destroy);
        fn_117_3290(members + 0x20C, destroy);
        fn_27_19F194(members + 0x70, destroy);
        fn_27_1A52A4(object, destroy);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
