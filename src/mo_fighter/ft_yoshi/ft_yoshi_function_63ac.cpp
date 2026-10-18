#include <stddef.h>
#pragma force_active on

extern "C" void* fn_95_3EE8(void*, short);
extern "C" void* fn_95_3F6C(void*, short);
extern "C" void* fn_95_6448(void*, short);
extern "C" void* fn_95_64A4(void*, short);
extern "C" void* fn_95_6EBC(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_95_63AC(void* object, short deleting) {
    if (object != 0) {
        fn_95_3EE8(static_cast<unsigned char*>(object) + 0xDE4, -1);
        fn_95_3F6C(static_cast<unsigned char*>(object) + 0xDD0, -1);
        fn_95_6448(static_cast<unsigned char*>(object) + 0x930, -1);
        fn_95_64A4(static_cast<unsigned char*>(object) + 0xBC, -1);
        fn_95_6EBC(static_cast<unsigned char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
