#include <types.h>
#pragma force_active on

extern "C" void fn_8030CEB0(int, int, s8*);

extern "C" void fn_8030CE84(int a, int b) {
    s8 sp8 = 0;
    fn_8030CEB0(a, b, &sp8);
}
