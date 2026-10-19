#include <types.h>
#pragma force_active on

extern "C" void fn_111_4E4C(void* p, s16 v);
extern "C" void fn_111_3D2C(void* p, s16 v);
extern "C" void __dl__FPv(void* p);

extern "C" u8* fn_111_4DE0(u8* self, s16 flag) {
    s16 neg = -1;
    if (self != 0) {
        fn_111_4E4C(self + 0x24, neg);
        fn_111_3D2C(self, neg);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
