#include <stddef.h>
#pragma force_active on

extern "C" void fn_116_3CA4(void*, short);
extern "C" void fn_116_3D28(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
void operator delete(void*);

extern "C" void* fn_116_13310(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_116_3CA4(storage + 0x28, -1);
        fn_116_3D28(storage + 0x14, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
