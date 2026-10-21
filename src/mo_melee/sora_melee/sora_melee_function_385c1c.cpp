#include <types.h>
#pragma force_active on

struct X { u32 a, b, c; };

extern "C" u32 fn_27_385C1C(X *p) {
    return (p->c >> 1) & 1;
}
