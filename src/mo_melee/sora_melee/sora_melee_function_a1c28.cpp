#include <types.h>
#pragma force_active on

struct X {
    u32 a;
    u32 b;
    u32 f0 : 15;
    u32 f1 : 1;
};

extern "C" u32 fn_27_A1C28(const X* obj) {
    return obj->f1;
}
