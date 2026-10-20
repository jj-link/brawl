#include <types.h>
#pragma force_active on

struct X {
    int a;
    int b;
    int c;
};

extern "C" s32 fn_27_295D74(struct X *obj) {
    return obj->c >> 28;
}
