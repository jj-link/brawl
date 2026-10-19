#include <st/module.h>
#pragma force_active on

extern "C" {
void operator delete(void*);
void fn_107_2050(void*, short);
void fn_107_3E04(void*, short);
}

extern "C" void* fn_107_69C8(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_107_2050((storage + 0x20), 0);
        fn_107_3E04(object, 0);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
