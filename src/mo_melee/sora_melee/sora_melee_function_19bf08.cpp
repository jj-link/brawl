#include <types.h>
#pragma force_active on

struct X {
    u32 _0;
    u32 _4;
    u32 _8;
};

extern "C" u32 fn_27_19BF08(X* p) {
    return (p->_8 >> 25) & 1;
}
