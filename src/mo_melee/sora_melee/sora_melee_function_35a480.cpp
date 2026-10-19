#include <types.h>
#pragma force_active on

extern "C" void fn_27_35C0C4(void* a, void* b, int c, int d, int e, int f);

extern "C" int fn_27_35A480(int a0, void* a1, u8* a2, int a3, int a4, int a5, int a6) {
    u8* p = *(u8**)(a2 + 8);
    fn_27_35C0C4(a1, *(void**)(p + 0x28), a3, a4, a5, a6);
    return 1;
}
