#include <types.h>
#pragma force_active on

extern "C" void fn_803103E0(int a, int b, s8* p);

extern "C" void fn_803103B4(int a, int b) {
    s8 sp8;
    sp8 = 0;
    fn_803103E0(a, b, &sp8);
}
