#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_A6978(void* ptr, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_27_CA64C(u8* self, int doDelete) {
    if (self) {
        __destroy_arr(self + 0xC, fn_27_A6978, 0x24, 0xC);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
