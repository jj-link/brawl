#include <types.h>
#pragma force_active on

extern "C" void fn_27_25290();
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);

struct fn27ArrOwner {
    u8 pad[0xC];
};

extern "C" fn27ArrOwner* fn_27_CFF98(fn27ArrOwner* self, int doDelete) {
    if (self) {
        __destroy_arr((u8*)self + 0xC, (void (*)(void*, int))fn_27_25290, 0x30, 0x22);
        if (doDelete > 0) {
            ::operator delete(self);
        }
    }
    return self;
}
