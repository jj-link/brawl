#include <types.h>
#pragma force_active on

struct Fld {
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

extern "C" void fn_27_19CD5C(u8* p, u32 v) {
    Fld* f = (Fld*)(p + 8);
    f->b = v;
}
