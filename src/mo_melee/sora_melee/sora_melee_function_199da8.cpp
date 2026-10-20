#include <types.h>
#pragma force_active on

struct X {
    u32 a;
    u32 b;
    u32 c : 15;
    u32 d : 1;
    u32 e : 16;
};

extern "C" u32 fn_27_199DA8(X *p) {
    return p->d;
}
