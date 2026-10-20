#include <types.h>
#pragma force_active on

extern "C" void fn_27_87868(void* p, s16* out);

extern "C" void fn_27_87940(void* p) {
    s16 v = -1;
    fn_27_87868(p, &v);
}
