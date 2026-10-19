#include <types.h>
#pragma force_active on

extern "C" void* fn_107_52D0(void* object, s16 deleting);
extern "C" void* fn_107_568C(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_107_5254(void* object, s16 deleting) {
    if (object != 0) {
        fn_107_52D0(static_cast<char*>(object) + 0x8c0c, -1);
        if (object != 0) {
            fn_107_568C(object, 0);
        }
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
