#include <types.h>
#pragma force_active on

extern "C" void fn_27_1999C4(void* ptr, int a, int b);
extern "C" void fn_27_19BF3C(void* ptr, int a, int b);
extern "C" void fn_27_150320(void* a, void* b, short c, void* d, void* e);

extern "C" void* fn_114_98FC(char* self, void* arg, int arg2) {
    fn_27_1999C4(self, 10, 0);
    fn_27_19BF3C(self + 0x584, 2, 0);
    fn_27_150320(self + 0x5b8, arg, (short)arg2, self, self + 0x584);
    return self;
}
