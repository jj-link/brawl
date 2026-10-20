#include <types.h>
#pragma force_active on

struct X {
    s32 a;
    s32 b;
    s32 c;
};

extern "C" s32 fn_27_19D408(X *p) {
    return p->c >> 27;
}
