#include <stddef.h>
#pragma force_active on

extern "C" void* fn_27_565F0(void*, short);
extern "C" void* fn_119_11CF8(void*, short);
void operator delete(void*);

extern "C" void* fn_119_11D38(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_27_565F0(storage + 0xC, -1);
        fn_119_11CF8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
