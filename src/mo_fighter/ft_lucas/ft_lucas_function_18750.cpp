#include <types.h>
#pragma force_active on

extern "C" void fn_114_57E0(void* object, short deleting);
extern "C" void fn_114_187BC(void* object, short deleting);
extern "C" void __dl__FPv(void* array);

extern "C" void* fn_114_18750(void* self, int flags) {
    if (self != 0) {
        fn_114_57E0(static_cast<char*>(self) + 0x1F8C, -1);
        fn_114_187BC(static_cast<char*>(self) + 0x4, -1);
        if ((s16)flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
