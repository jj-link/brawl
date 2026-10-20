#include <types.h>
#pragma force_active on

extern "C" void* fn_111_20E8(void* object, s16 deleting);
extern "C" void* fn_111_2184(void* object, s16 deleting);
extern "C" void* fn_111_21C4(void* object, s16 deleting);
extern "C" void* fn_27_C7770(void* object, s16 deleting);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_111_2518(void* self, s16 deleting) {
    if (self != NULL) {
        fn_111_20E8(static_cast<u8*>(self) + 0xdc, -1);
        fn_111_2184(static_cast<u8*>(self) + 0xc0, -1);
        fn_111_21C4(static_cast<u8*>(self) + 0x14, -1);
        if (self != NULL) {
            fn_27_C7770(self, -1);
        }
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
