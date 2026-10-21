#include <types.h>
#pragma force_active on

extern "C" void fn_802F9098(int, s8*);

extern "C" void fn_802F906C(int a) {
    s8 v = 1;
    fn_802F9098(a, &v);
}
