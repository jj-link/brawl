#include <types.h>
#pragma force_active on

extern "C" void fn_27_57BA0(void* storage, s16 value);
extern "C" void* fn_111_1E48(void* object, s16 deleting);
extern "C" void fn_111_1EA4(void* object, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_111_1DC8(void* object, s16 deleting) {
    if (object != 0) {
        u8* base = static_cast<u8*>(object);
        void* storage = base + 0x20;
        if (storage != 0) {
            fn_27_57BA0(storage, 0);
        }
        fn_111_1E48(base + 0x14, 0);
        fn_111_1EA4(base + 0x8, 0);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
