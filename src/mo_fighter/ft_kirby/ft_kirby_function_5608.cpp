#include <stddef.h>
#pragma force_active on

extern "C" void fn_27_D2904(void* member, short deleteFlag);
extern "C" void fn_96_5590(void* object, short deleting);
extern "C" void __dl__FPv(void* ptr);

// fn_96_5608: destroys the embedded member at +0x318 via fn_27_D2904 with
// flag -1, then runs the object's own cleanup fn_96_5590 with flag 0, and
// only a positive deleting flag releases the allocation itself. The object
// pointer is returned in every case.
extern "C" void* fn_96_5608(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_D2904(storage + 0x318, -1);
        if (object != 0) {
            fn_96_5590(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
