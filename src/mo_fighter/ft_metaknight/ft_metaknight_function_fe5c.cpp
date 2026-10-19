#include <types.h>
#pragma force_active on

extern "C" void fn_111_1EA4(void* object, s16 deleting);
extern "C" void fn_111_1E48(void* object, s16 deleting);

extern "C" void* fn_111_FE5C(void* self, s16 deleting) {
    s16 zero = 0;
    if (self != 0) {
        fn_111_1EA4(static_cast<u8*>(self) + 0x20, zero);
        if (self != 0) {
            fn_111_1E48(static_cast<u8*>(self) + 0x8, zero);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
