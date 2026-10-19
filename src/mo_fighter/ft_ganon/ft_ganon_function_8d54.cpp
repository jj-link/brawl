#include <types.h>
#pragma force_active on

extern "C" void* fn_27_C74E8(void* object, s16 deleting);
extern "C" void* fn_109_1918(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_109_8D54(void* object, s16 deleting) {
    if (object != 0) {
        fn_27_C74E8(static_cast<char*>(object) + 0xC994, -1);
        fn_109_1918(object, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
