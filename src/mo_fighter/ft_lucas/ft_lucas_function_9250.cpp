#include <types.h>
#pragma force_active on

extern "C" void fn_27_CC060(void*, int, int);
extern "C" void fn_27_2556C(void*, void*, void*, void*, void*);
extern "C" unsigned char lbl_27_bss_298[];

extern "C" void* fn_114_9250(void* self, void* argument, void* data) {
    fn_27_CC060(self, 1, 0);
    fn_27_2556C((unsigned char*) self + 0x50, argument, self, data,
                 lbl_27_bss_298);
    return self;
}
