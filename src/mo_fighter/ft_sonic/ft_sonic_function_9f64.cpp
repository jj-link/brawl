#include <types.h>
#pragma force_active on

extern "C" void* fn_27_C74E8(void* object, s16 deleting);
extern "C" void* fn_123_18D8(void* owner, s16 deleting);
extern "C" void __dl__FPv(void* object);

extern "C" void* fn_123_9F64(void* self, s16 deleting) {
    if (self != 0) {
        fn_27_C74E8(static_cast<char*>(self) + 0xD5C4, -1);
        fn_123_18D8(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
