#pragma force_active on
#include <types.h>
extern "C" void* fn_96_8608(void*, short);
extern "C" void* fn_96_8104(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_96_8668(void* object, s16 deleting) {
    if (object != 0) {
        fn_96_8608(static_cast<char*>(object) + 0x8E14, -1);
        if (object != 0) {
            fn_96_8104(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
