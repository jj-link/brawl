#include <types.h>
#pragma force_active on

extern "C" void fn_27_D2FF0(void* self, s32 a, s32 b);
extern "C" void fn_27_61454(void* a, void* b, void* c, void* d, void* e, void* f);
extern "C" u32 lbl_27_bss_4694[];
extern "C" u32 lbl_27_bss_46AC[];

extern "C" void* fn_114_9750(void* self, void* arg1, void* arg2) {
    fn_27_D2FF0(self, 1, 0);
    fn_27_61454((char*)self + 0xAC, arg1, self, lbl_27_bss_4694, lbl_27_bss_46AC, arg2);
    return self;
}
