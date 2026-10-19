#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_CC060(void* self, s32 a, s32 b);
void fn_27_2556C(void* a, void* b, void* c, void* d, void* e);
extern u8 lbl_27_bss_298[];

void* fn_103_7934(void* self, void* arg2, void* arg3) {
    fn_27_CC060(self, 1, 0);
    fn_27_2556C(static_cast<u8*>(self) + 0x50, arg2, self, arg3, lbl_27_bss_298);
    return self;
}
}
