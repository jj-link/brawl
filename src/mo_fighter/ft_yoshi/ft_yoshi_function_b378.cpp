#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_1F9CC(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_95_1AA4(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_95_B378(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_1F9CC(members + 0x22288, memberDeleting);
        fn_27_C74E8(members + 0x22274, memberDeleting);
        fn_95_1AA4(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
