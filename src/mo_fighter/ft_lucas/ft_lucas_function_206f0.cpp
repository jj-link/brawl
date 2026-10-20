#include <types.h>
#pragma force_active on

void operator delete(void*);

extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void fn_114_4854(void*, short);
}

extern "C" void* fn_114_206F0(void* object, short deleting) {
    void* result = object;
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_13C90(members + 0x9c, memberDeleting);
        fn_27_21038(members + 0x88, memberDeleting);
        fn_114_4854(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return result;
}
