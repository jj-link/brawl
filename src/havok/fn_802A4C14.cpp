#include <types.h>
#pragma force_active on

extern "C" void fn_802A4C40(int, int, s8* p);

extern "C" void fn_802A4C14(void) {
    s8 sp8;
    int a;
    int b;
    sp8 = 0;
    fn_802A4C40(a, b, &sp8);
}
