#include <st/module.h>
#pragma force_active on

extern "C" {
void* fn_105_E17C(void* object, short deleting);
void* fn_105_5220(void* object, short deleting);
void* fn_105_5290(void* object, short deleting);
void __dl__FPv(void*);
}

extern "C" void* fn_105_63AC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_105_E17C(storage + 0xE0, -1);
        fn_105_5220(storage + 0x30, -1);
        fn_105_5290(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
