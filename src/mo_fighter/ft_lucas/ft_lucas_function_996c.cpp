#include <types.h>
#pragma force_active on

extern "C" void fn_27_CB410(void* self, s32 a, s32 b);
extern "C" void fn_27_B215C(void* field, void* a, void* self, void* b, void* c, void* d);

extern "C" void* fn_114_996C(void* self, void* a, void* b, void* c, void* d) {
    fn_27_CB410(self, 1, 0);
    fn_27_B215C((char*)self + 0x50, a, self, b, c, d);
    return self;
}
