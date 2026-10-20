#include <types.h>
#pragma force_active on

extern "C" void fn_114_3E98(void*, short);
extern "C" void fn_114_1DFB0(void*, short);
extern "C" void fn_114_3F18(void*, short);

void operator delete(void*);

extern "C" void* fn_114_1DF38(void* object, short deleting) {
    void* result = object;
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_114_3E98(members + 0x68, memberDeleting);
        fn_114_1DFB0(members + 0x30, memberDeleting);
        fn_114_3F18(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return result;
}
