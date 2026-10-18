#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3FE4(void* object, short deleting);
extern "C" void* fn_114_4068(void* object, short deleting);
extern "C" void* fn_114_6F14(void* object, short deleting);
extern "C" void* fn_114_6F70(void* object, short deleting);
extern "C" void* fn_114_7988(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_6E78(void* object, short deleting) {
    if (object != 0) {
        fn_114_3FE4(static_cast<char*>(object) + 0xdd8, -1);
        fn_114_4068(static_cast<char*>(object) + 0xdc4, -1);
        fn_114_6F14(static_cast<char*>(object) + 0x930, -1);
        fn_114_6F70(static_cast<char*>(object) + 0xbc, -1);
        fn_114_7988(static_cast<char*>(object) + 0x10, -1);
        fn_27_C74E8(object, -1);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
