#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3FE4(void*, short);
extern "C" void* fn_114_4068(void*, short);
extern "C" void* fn_114_20634(void*, short);
extern "C" void* fn_114_40C8(void*, short);
extern "C" void* fn_114_20690(void*, short);
extern "C" void* fn_27_C74E8(void*, short);

extern "C" void* fn_114_20598(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_114_3FE4(members + 0x138, memberDeleting);
        fn_114_4068(members + 0x124, memberDeleting);
        fn_114_20634(members + 0xf4, memberDeleting);
        fn_114_40C8(members + 0x50, memberDeleting);
        fn_114_20690(members + 0x10, memberDeleting);
        fn_27_C74E8(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
