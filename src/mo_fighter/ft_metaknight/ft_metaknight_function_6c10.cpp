#include <types.h>
#pragma force_active on

extern "C" void fn_27_CB410(void* object, s32 a, s32 b);
extern "C" void fn_27_B215C(void* object, void* a, void* b, void* c, void* d, void* e);

extern "C" void* fn_111_6C10(void* self, void* a, void* b, void* c, void* d) {
    fn_27_CB410(self, 1, 0);
    fn_27_B215C((u8*)self + 0x50, a, self, b, c, d);
    return self;
}
