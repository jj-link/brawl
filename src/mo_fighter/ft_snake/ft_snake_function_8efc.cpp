#include <stddef.h>
#pragma force_active on

extern "C" void* fn_122_40A0(void* object, short deleting);
extern "C" void* fn_122_4124(void* object, short deleting);
extern "C" void* fn_122_8F98(void* object, short deleting);
extern "C" void* fn_122_8FF4(void* object, short deleting);
extern "C" void* fn_122_9A0C(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);

void operator delete(void*);

extern "C" void* fn_122_8EFC(void* object, short deleting) {
    if (object != 0) {
        unsigned char* storage = static_cast<unsigned char*>(object);
        fn_122_40A0(storage + 0xe24, -1);
        fn_122_4124(storage + 0xe10, -1);
        fn_122_8F98(storage + 0x930, -1);
        fn_122_8FF4(storage + 0xbc, -1);
        fn_122_9A0C(storage + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
