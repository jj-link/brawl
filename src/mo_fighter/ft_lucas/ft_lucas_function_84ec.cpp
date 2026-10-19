#include <types.h>
#pragma force_active on

extern "C" void fn_27_22A38(void* p, s16 n);
extern "C" void fn_27_1A2910(void* p, s16 n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_114_84EC(void* self, s16 flag) {
    if (self != 0) {
        s16 neg = -1;
        fn_27_22A38(reinterpret_cast<u8*>(self) + 0x34, neg);
        fn_27_1A2910(self, neg);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
