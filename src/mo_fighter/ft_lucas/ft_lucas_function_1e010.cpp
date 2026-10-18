#include <types.h>
#pragma force_active on

extern "C" void* fn_114_3FE4(void* object, short deleting);
extern "C" void* fn_114_4068(void* object, short deleting);
extern "C" void* fn_114_5A38(void* object, short deleting);
extern "C" void* fn_114_40C8(void* object, short deleting);
extern "C" void* fn_114_5120(void* object, short deleting);
extern "C" void* fn_27_C74E8(void* object, short deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_114_1E010(void* object, short deleting) {
    if (object != 0) {
        short flag = -1;
        fn_114_3FE4(static_cast<char*>(object) + 0x110, flag);
        fn_114_4068(static_cast<char*>(object) + 0xfc, flag);
        fn_114_5A38(static_cast<char*>(object) + 0xec, flag);
        fn_114_40C8(static_cast<char*>(object) + 0x48, flag);
        fn_114_5120(static_cast<char*>(object) + 0x10, flag);
        fn_27_C74E8(object, flag);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
