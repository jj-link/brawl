#include <types.h>
#pragma force_active on

extern "C" void* fn_114_5D0C(void* object, short deleting);
extern "C" void* fn_114_62A0(void* object, short deleting);
extern "C" void* __dl__FPv(void* object);

extern "C" void* fn_114_6230(void* self, signed short deleting) {
    if (self != NULL) {
        fn_114_5D0C(static_cast<char*>(self) + 0x118F8, -1);
        fn_114_62A0(static_cast<char*>(self) + 4, -1);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
