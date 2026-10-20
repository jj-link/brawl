#include <types.h>
#pragma force_active on

extern "C" void* fn_27_13C90(void*, short);
extern "C" void* fn_27_21038(void*, short);
extern "C" void* fn_111_3F04(void*, short);
void operator delete(void*);

extern "C" void* fn_111_105BC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_27_13C90(members + 0x54, memberDeleting);
        fn_27_21038(members + 0x40, memberDeleting);
        fn_111_3F04(members + 4, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
