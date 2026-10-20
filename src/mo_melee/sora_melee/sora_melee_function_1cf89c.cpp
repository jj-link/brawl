#include <types.h>
#pragma force_active on

struct Data {
    u32 _0;
    u32 _4;
    u32 _8;
};

extern "C" u32 fn_27_1CF89C(Data *p) {
    return (p->_8 >> 13) & 1;
}
