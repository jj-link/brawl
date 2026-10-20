#include <st/module.h>
#pragma force_active on

extern "C" {
void* fn_121_2CE0(void*, short);
void* fn_121_5318(void*, short);
void* fn_27_19E99C(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_121_5378(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_121_2CE0(storage + 0x85C, -1);
        fn_121_5318(storage + 0x19C, -1);
        fn_27_19E99C(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
