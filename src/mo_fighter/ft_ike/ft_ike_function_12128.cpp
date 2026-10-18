#include <stddef.h>
#pragma force_active on

extern "C" void* fn_119_385C(void* object, short deleting);
extern "C" void* fn_119_38E0(void* object, short deleting);
extern "C" void* fn_119_120CC(void* object, short deleting);
extern "C" void* fn_119_12054(void* object, short deleting);
extern "C" void* fn_119_11F38(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

extern "C" void* fn_119_12128(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_119_385C(storage + 0x138, -1);
        fn_119_38E0(storage + 0x124, -1);
        fn_119_120CC(storage + 0x108, -1);
        fn_119_12054(storage + 0x64, -1);
        fn_119_11F38(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
